# REST API Changelog

## Hotfix v1.1.1

### Fixes

* Changed all occurances of `Id` to `id` for uniformity.

## Release v.1.1

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