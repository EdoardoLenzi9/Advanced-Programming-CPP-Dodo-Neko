# REST API Description

[TOC]

## General information

Default request and responses are sent on all interactions. 

The specified data in the specific endpoints is to be appended into the `data` section of the default objects.

### Default response format
```json=
{
    "status": {
        "code": "<num>",
        "description": "<string>"
    },
    "data": {
        "<custom json object>"
    }
}
```
### Default request format
```json=
{
    "auth": {
        "sid":"<string>"
    },
    "data": {
        "<custom json object>"
    }
}
```
### Default response codes

A list of common server response codes. The descriptions are only a general idea. For the actual error message, use your own description and throw it into the `status.description` field of the default response.

|Code | State | Description |
| ---- | ---- | ---- |
| 200 | success | Everything was done according to request |
| 401 | failure | Request not possible, authentication required or auth level too low. Also returned when authentication fails on the `/user/auth` endpoint. |
| 406 | failure | failed to parse JSON |
| 501 | failure | not implemented, returned when accessing an invalid endpoint |

## Endpoints

### /meta

#### /meta/api_ver GET  (no-auth)

Get basic info about the hotel.

```json=
{
    "version":"<number>"
}
```

### /hotel

#### /hotel GET (no-auth)

Get basic info about the hotel.

```json=
{
    "name":"<string>",
    "contact":"<string>",
    "address":"<string>",
    "description":"<string>"
}
```

### /user

#### /user/list POST (auth-level staff, admin)

Return a list of all users, staff and admin only.

Request

```json=
{

}
```

Response

```json=
{
	"users":[
		"<userid>":{
        "firstname":"<string>",
        "lastname":"<string>",
        "email":"<string>",
        "birthdate":"<long> unix time",
        "address":"<string>",
        "userid":"<num>"
        "roleid":"<num>"
		},
		...
	]
}
```

#### /user POST (auth-level customer, staff, admin)

Return information about the currently logged in user

Request

```json=
{

}
```

Response

```json=
{
    "firstname":"<string>",
    "lastname":"<string>",
    "email":"<string>",
    "birthdate":"<long> unix time",
    "address":"<string>",
    "userid":"<num>"
    "roleid":"<num>"
}
```

#### /user/update POST (auth-level customer, staff, admin)

Update user data. Users should only be able to update their own data. Staff and admins can update any user.

If a field string is empty, leave the field in the database as-is.

Request

```json=
{
    "userid":"<num>",
    "roleid":"<num>", 
 	"firstname":"<string>",
    "lastname":"<string>",
    "email":"<string>",
    "birthdate":"<long> unix time",
    "address":"<string>",
    "password":"<string>"
}
```

Response

```json=
{

}
```

#### /user/logout POST (auth-level

Logout the current user.

Request 

```json=
{

}
```

Response

```json=
{

}
```

#### /user/register POST (no-auth)

Create a new user. New users should always be with the lowest possible role.

Request

```json=
{
    "firstname":"<string>",
    "lastname":"<string>",
    "email":"<string>",
    "birthdate":"<long> unix time",
    "address":"<string>",
    "password":"<string>"
}
```

Response

```json=
{
    
}
```
#### /user/auth POST (no-auth)

Request

```json=
{
    "email":"<string>",
    "password":"<string>"
}
```

Response 

```json=
{
	"sid":"<string>"
}
```

### /room

#### /room/list POST  (no-auth)

Get a list of all rooms available during a specified period. Dates are specified in Unix time.

Price calculation is done as follows:

Each room has a feature of type `0` as the price of the room itself. Each additional feature `>0` has a specific price and an amount attached to it. The final price is sum of all features (times their respective amounts).

Request

```
{
	"startdate":"<long>",
	"enddate":"<long>"
}
```

Response

```json=
{
    "rooms":[
        {
            "features":[
                {
                    "id":"<num>",
                    "name":"<string>",
                    "price":"<num>",
                    "amount":"<num>",
                },	
                ...
            ],
            "roomnumber":"<num>",
            "roomid":"<num>"
        },
        ...
	]
}
```

### /book 

#### /book/confirmpayment POST (auth-level staff, admin)

Allows a manager to confirm a payment.

Request

```json=
{
	"<bookid>":"<num>"
}
```

Response

```json=
{

}
```

#### /book/create POST (auth-level customer, staff, admin)

Create a booking.

Request

```json=
{
    "roomid":"<num>",
    "arrival":"<long> unix time",
    "departure":"<long> unix time",
}
```

Response

```json=
{

}
```

#### /book/list POST (auth-level customer, staff,admin)

Returns a list of all bookings linked to the currently logged in person. If the user is a staff member, this should return all bookings. The server can determine the user's role and userid via the provided SID.

Request

```json=
{
    
}
```

Response

```json=
{
    "bookings":[
        <bookid> {
            "room":{
            	"roomid":"<num>",
                "features":[
                {
                    "id":"<num>",
                    "name":"<string>",
                    "price":"<num>",
                    "amount":"<num>",
                },	
                ...
                ],
			},
			"arrival":"<long> unix time",
            "departure":"<long> unix time",
            "paid":"<bool>",
            "price":"<num>",
            "user": {
                "firstname":"<string>",
                "lastname":"<string>",
                "email":"<string>",
                "birthdate":"<long> unix time",
                "address":"<string>",
                "userid":"<num>"
                "roleid":"<num>"
            }
        },
        ...
    ]
}
```

#### /book/update POST (auth-level customer, staff, admin)

Update a booking. For customer, only allow to update his own bookings - and if they have not yet paid. 

If the requested changed date is not available, this should return 401.

Staff and admin can change all bookings.

Request

```json=
{
    "bookid":"<num>",
    "arrival":"<string>(YYYY-MM-DD)",
    "departure":"<string>(YYYY-MM-DD)",
}
```

Response

```json=
{

}
```

#### /book/delete POST (auth-level customer, staff, admin)

Delete a booking for a room. Users are only allowed to delete their own bookings. 

Staff and admins can delete all bookings.

Request

``` json=
{
    "bookid":"<num>"
}
```

``` json=
{

}
```