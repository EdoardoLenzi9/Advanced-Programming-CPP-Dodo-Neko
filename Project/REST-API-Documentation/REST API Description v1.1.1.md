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

#### /user POST (auth-level customer, staff, management)

Return information about the currently logged in user

Request

```json=
{

}
```

Response

```json=
{
    "firstName":"<string>",
    "lastName":"<string>",
    "email":"<string>",
    "birthdate":"<string>(YYYY-MM-DD)",
    "address":"<string>",
    "userid":"<num>"
    "roleid":"<num>"
}
```

#### /user/update POST (auth-level customer, staff, admin)

Update user data. Users should only be able to update their own data. Staff and admins can 

Request

```json=
{
    "firstName":"<string>",
    "lastName":"<string>",
    "email":"<string>",
    "birthdate":"<string>(YYYY-MM-DD)",
    "address":"<string>",
    "password":"<string>(sha256)",
    "userid":"<num>",
    "roleid":"<num>"
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
    "successful":"boolean" // 1 is yes
}
```

#### /user/register POST (no-auth)

Create a new user. New users should always be with the lowest possible role.

Request

```json=
{
    "firstName":"<string>",
    "lastName":"<string>",
    "email":"<string>",
    "birthdate":"<string>(YYYY-MM-DD)",
    "address":"<string>",
    "password":"<string>(sha256)"
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
    "username":"<string>",
    "password":"<string>(sha256)"
}
```

Response 

```json=
{
	"sid":"<string>"
}
```

### /room

#### /room/update POST (auth-level staff, admin)

Staff and admins are supposed to be able to change the features of a room and change prices aswell.

Request

```json=
{
    "roomID":"<num>",
    "coordinates":{
        "tlx":"<float>",
        "tly":"<float>",
        "brx":"<float>",
        "bry":"<float>"
    },
    "features":[
        {
            "id":"<num>",
            "name":"<string>",
            "priceMultiplier":"<num>",
            "amount":"<num>"
        },
        ...
    ],
    "baseprice":"<float>"
}
```


``` json=
{
    "successful":"boolean" //1 means yes
}
```

#### /room/list GET  (no-auth)

Get a list of all rooms

Response

```json=
{
    "rooms":[
        "<roomID>",
        ...
    ]
}
```

#### /room/\<roomID\> GET  (no-auth)

Allows requesting info on a room id. For example /room/1 to get info about room #1

Response

```json=
{
    "roomID":"<num>"
    "coordinates":{
        "tlx":"<float>",
        "tly":"<float>",
        "brx":"<float>",
        "bry":"<float>"
    },
    "features":[
        {
            "id":"<num>",
            "name":"<string>",
            "priceMultiplier":"<num>",
            "amount":"<num>"
        },
        ...
    ],
    "basePrice":"<num>"
}
```

### /book 

#### /book/check POST (no-auth)

Check if a room is available for a set time frame.

Request

```json=
{
    "roomID":"<num>",
    "arrival":"<string>(YYYY-MM-DD)",
    "departure":"<string>(YYYY-MM-DD)"
}
```

Response

```json=
{
    "available":"boolean" // 1 is available
    "bookedDates":[
        "<string>(YYYY-MM-DD)",
        ...
    ]
}
```

#### /book/create POST (auth-level customer, staff, admin)

Create a booking.

Request

```json=
{
    "roomID":"<num>",
    "userID":"<num>",
    "arrival":"<string>(YYYY-MM-DD)",
    "departure":"<string>(YYYY-MM-DD)",
}
```

Response

```json=
{
    "successful":"boolean"
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
        <bookID>,
        ...
    ]
}
```

#### /book/\<id\> POST (auth level customer, staff, admin)

On POST, the Server determines the user via the sent SID. If the user is a customer, and asks for one of his own bookings, return

Request

```json=
{
    "id":"<bookID>"
}
```

Response

```json=
{
    "booking":{
        "roomID":"<num>",
        "userID":"<num>",
        "bookingID":"<num>",
        "arrival":"<string>(YYYY-MM-DD)",
        "departure":"<string>(YYYY-MM-DD)",
        "paid":"boolean" //1 means paid
    }
}
```

#### /book/update POST (auth-level customer, staff, admin)

Update a booking. For customer, only allow to update his own bookings - and if they have not yet paid.

Staff and admin can change all bookings.

Request

```json=
{
    "roomID":"<num>",
    "userID":"<num>",
    "bookID":"<num>",
    "arrival":"<string>(YYYY-MM-DD)",
    "departure":"<string>(YYYY-MM-DD)",
}
```

Response

```json=
{
    "successful":"boolean" // 1 means true
}
```

#### /book/delete POST (auth-level customer, staff, admin)

Delete a booking for a room. Users are only allowed to delete their own bookings. 

Staff and admins can delete all bookings.

Request

``` json=
{
    "bookID":"<num>"
}
```

``` json=
{
    "successful":"boolean" //1 means yes
}
```