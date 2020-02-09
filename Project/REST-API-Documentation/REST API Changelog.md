# REST API Changelog

## Hotfix v1.3.1

* small change to the `/room/list` endpoint: now contains a roomnumber and a roomid, instead of being an array of named ids.
* fixed some spelling mistakes:
  * in `/book/create` -> `departure`
  * in `/room/list` -> `enddate`
* fixed incorrect array addressing of the `/book/list` endpoint.
* added `roomnumber` to the `room` object of the `/book/list` endpoint.
* fixed incorrect array adressing of the `/user/list` endpoint.

## Release v1.3

Completely redesigned the REST API Implementation:

* All occurances of time have been changed to be in Unix-Time.
* All occruances of passwords are changed to be clear-text as hashing should be done on the server.
* `/user/list` was added to return a list of users for administrative use.
* `/room/list` has been completely redesigned to only return a list of bookings depending on a date range. Instead of returning all rooms, it will return the rooms available during that time period, including their features baked into the room object.
* `/room/<roomid>` was completely removed, as features come backed into `/room/list` now.
* `/room/update` was completely removed.
* `/book/confirmpayment` was removed to allow managers to confirm the received payment on a booking without the Update-Room functionality.
* `/book/check` was completely removed, checking the availability of a room is baked into `/room/list` now.
* `/book/create` was reworked. The `userid` was removed from the request (to be determined via the `sid`). Removed the `successful` from the response, use statuscode instead.
* `/book/list` was completely reworked to return a list of booking objects containing all the needed information like userdata and roomdata (including features).
* `/book/update` was simplified to only allow changing the arrival and departure times.
* Removed the `successful` from the response in `/book/delete`, use statuscode instead. 

## Hotfix v1.1.2

### Fixes

* Fixed the wording in the `/user/update` endpoint. Sending an empty field should mean "don't change it"
* removed all occurances of camelcase in the specification, since it was completely random. Everything is lowercase now.
* removed `successful` as a response from `/room/update` - use the status code in the default response instead.
* removed `successful` as a response from `/user/logout` - use the status code in the default response instead.
* changed `username` to `email` in `/user/auth`
* added 2 new status codes: ``

## Hotfix v1.1.1

### Fixes

* Changed all occurances of `Id` to `id` for uniformity.

## Release v1.1

### Additions

* New endpoint requirement: `/book/<id>`, which allows accessing information for a specific booking.
* New endpoint requirement: `/meta/api_ver`, which returns the current API version the server is running
* Added a list of common server response codes, mostly according to official [HTTP status code](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes) conventions 

### Changes

* `/book/list` should now return a list of book-IDs depending on the user
* `/user` should now also return the `userId` and the `roleId` of the querying user
* `/user/update` now also contains the `userId` and the `roleId` fields. For customer and staff members, these fields should be ignored (don't allow users to change their own Ids). For Admins the fields should be updated correspondingly
* `/user/auth` now needs to return a SID
* `/user/update` no longer returns `successful` in the response data. Use the status code of the default response instead.

## Release v1.0

Initial Release