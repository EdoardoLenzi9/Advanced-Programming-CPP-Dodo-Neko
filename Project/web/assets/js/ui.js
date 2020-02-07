///////////////////////////////
/////// local variables ///////
///////////////////////////////


// please change this to your server
//var serverUrl = "https://e06f6d86-e0bd-4a75-a8fe-bfcf40cfe849.mock.pstmn.io"
var serverUrl = "http://localhost:8080"
// filled via rest api
var loggedIn = 0;

////////////////////////////////
// data objects for local use //
////////////////////////////////

// constants 

const defaultRequest = {
	"auth": {
		"sid": null
	},
	"data": {
	}
};

// filled via rest api

var user = {
	"firstname": "",
	"lastname": "",
	"email": "",
	"birthday": "",
	"address": "",
	"password": "",
	"userid": "",
	"roleid": ""
};

///////////////////////////////
/////// local functions ///////
///////////////////////////////

// shows different navbar items depending on the group of the user.
// potentially a security issue, but pratically, api calls from users
// without the proper role are rejected by the server anyway. still 
// not a very good solution for the problem. 

// a possible solution might be sending in the actual admin pages over
// the api if a logged in user requests them, depending on the role - 
// therefore literally only having the code locally when the server agrees.
// still, this would need more server code yet.

// roleid: 
// 0 = guest
// 1 = customer
// 2 = manager
// 3 = admin
function showElementsbyState(){
	if (loggedIn > 0){
		$('#nav-register').addClass('d-none');

		if (user.roleid > 1){
			$('#nav-settings').removeClass('d-none');
		}
		if (user.roleid > 2){
			$('#nav-manage').removeClass('d-none');
		}
		if (user.roleid > 3){
			$('#nav-admin').removeClass('d-none');
			$('#nav-debug').removeClass('d-none');
		}

		$('#btn-login-dropdown').addClass('d-none');
		$('#btn-logout').removeClass('d-none');
		$('#btn-settings').removeClass('d-none');
	}
}

function round(num){
	// https://stackoverflow.com/questions/11832914/round-to-at-most-2-decimal-places-only-if-necessary/18358056#18358056
	return +(Math.round(num + "e+2") + "e-2");
}

function checkLoginState(){
	//TODO: define an endpoint to determine the valid state of a SID
}

// this is a function i found which corrects the missing headers
// for the $.post function. without application/json the server
// doesnt really know what to do with the data 
$.postJSON = function(url, data, successcallback) {
	return jQuery.ajax({
		'type': 'POST',
		'url': url,
		'contentType': 'application/json',
		'data': JSON.stringify(data),
		'dataType': 'json',
		'success': successcallback,
		'error': function(){ alert("accessing the api failed"); },
		'timeout': 3000
	});
};

function loadSettings(){

	$('#frm-email').text(user.email);
	$('#frm-firstname').text(user.firstname);
	$('#frm-lastname').text(user.lastname);
	$('#frm-birthday').text(user.birthday);
	$('#frm-userid').text(user.userid);
	$('#frm-roleid').text(user.roleid);

	if (user.roleid > 1){
		$('#frm-userid').attr('disabled', false);
		$('#frm-roleid').attr('disabled', false);
	}
}

function loadMainPage(){
	window.location = window.location.origin;
}

/*
	Implementation of the /hotel endpoint
*/

function getHotelInfo(){
	$.getJSON(`${serverUrl}/hotel`,
		function(response) {
			if (response.status.code == "200" ){
				$('#cnt-hotelname').text(response.data.name);
				$('#cnt-contact').text(response.data.contact);
				$('#cnt-address').text(response.data.address);
				$('#cnt-description').text(response.data.description);
			} else {
				console.log("getting hotel info failed");
			}
 		 });
}

/* 
	Implementation of the /user endpoint
*/

function getUserInfo(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	if ( request.auth.sid ) {
		$.postJSON(`${serverUrl}/user`,
		request,
		function(response) {
			if ( response.status.code == "200" ){
				console.log("successful");
				user.firstname = response.data.firstname;
				user.lastname = response.data.lastname;
				user.email = response.data.email;
				user.birthday = response.data.birthdate;
				user.address = response.data.address;
				user.userid = response.data.userid;
				user.roleid = response.data.roleid;
				loggedIn = 1;
				showElementsbyState();
			} else {
				console.log("acquiring user info failed");
				console.log(response);
			}
		});
	}
}

function displayFeatures(roomid){

	$('#tbl-featurelist tbody tr').each (function (val) { $(this).remove(); })
	$.getJSON(`${serverUrl}/room/${roomid}`,
	function(response) {
		if (response.status.code == 200){
			console.log("success");
			features = response.data.features;

			for (var i = 0; i < features.length; i++) {
				$('#tbl-featurelist').append('<tr name="featurerow"><td>' + features[i].name + '</td><td>' + features[i].amount + '</td></tr>');
			}
		} else {
			console.log("getting roominfo failed");
			console.log(response);
		}
	});
}

/*
	Implementation of the /user/auth endpoint
*/

function login(){
	var request = defaultRequest;
	Cookies.remove('sid');

	request.auth.sid = Cookies.get('sid');
	
	request.data = {
			"email": $('#frm-username').val(),
			"password": $('#frm-password').val()
		}
	$.postJSON(`${serverUrl}/user/auth`,
	request, 
	function(response) {
		if (response.status.code == "200") {
			console.log("authentication successful");
			console.log(response.data.sid);
			Cookies.set('sid', response.data.sid, { expires: 7, path: '' }); // 7 days	
			loadMainPage();
		} else if (response.status.code == "401") {
			// TODO: needs a nicer way of displaying this, maybe some shaking-animation on the login menu
			alert("authentication failed");
		} else {
			alert("authentication failed due to unknown reasons (check log)");
			console.log("login failed")
			console.log(response);
		}
	});
	getUserInfo();
	showElementsbyState();
};

/*
	Implementation of the /user/logout endpoint
	TODO: make sure the server reacts properly in case an empty call comes along
*/

function logout(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	if ( request.auth.sid ){
		$.postJSON(`${serverUrl}/user/auth`,
		request, 
		function(response) {
			if(response.status.code == 200){
				Cookies.remove('sid');
				loadMainPage();
				loggedIn = 0;
			} else {
				console.log("logout went wrong");
				console.log(response);
			}
		});
	}
}

/*
	Implementation of the /user/register endpoint

	//TODO: change the alerts in this function to something nicer, 
	// like a shaking window or a shaking text box or something.

	//TODO: some sort of simple input validation. the server is 
	// validating inputs anyway, but no need to send garbage on purpose.
*/

function register(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	var empty = "0";

	if (! $('#frm-email').val() || ! $('#frm-pass').val() ) {
		alert("password or email empty");
		empty = 1;
	}

	request.data.email=$('#frm-email').val();
	request.data.password=$('#frm-pass').val();

	if (! $('#frm-firstname').val() || ! $('#frm-lastname').val() ) {
		alert("name not entered correctly");
		empty = 1;
	}

	request.data.firstname=$('#frm-firstname').val();
	request.data.lastname=$('#frm-lastname').val();

	if (! $('#frm-address').val() || ! $('#frm-birthday').val() ) {
		alert("address of birthday empty");
		empty = 1;
	}

	request.data.address=$('#frm-address').val();
	request.data.birthdate=$('#frm-birthday').val();

	if (! $('#cbx-terms').is(':checked') ) {
		alert("Please accept our terms!");
	}

	if (! empty && $('#cbx-terms').is(':checked') ) {
		$.postJSON(`${serverUrl}/user/register`,
		request, 
		function(response) {
			//TODO: Show a window, that registering was successful. 
			// then ask the user to click a button to reload, that
			// redirects to the login screen.

			if (response.status.code == "200") {
				loadMainPage();
			}
		});
	} else {
		console.log("fields incorrect, try again.");
	}
}

/*
	Implementation of the /user/update endpoint
*/

function userUpdate(){
	getUserInfo();

	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	request.data.firstname = $('#frm-firstname').val();
	request.data.lastname = $('#frm-lastname').val();
	request.data.email = $('#frm-email').val();
	request.data.birthdate = $('#frm-birthday').val();
	request.data.address = $('#frm-address').val();
	request.data.password = $('#frm-password').val();
	request.data.userid = $('#frm-userid').val();
	request.data.roleid = $('#frm-roleid').val();

	$.postJSON(`${serverUrl}/user/update`,
	request, 
	function(response) {
		if (response.status.code == 401){
			alert("no authentication");
		} else if (response.status.code != 200 ) {
			alert("something else went wrong...");
			console.log(response);
		}
	});
}

/* 
	Implementation of the /room/list endpoint
*/

/*
// this implementation suffers from asynchronity - actually in this piece of shit language
// you cant even make sure you actually have values in a variable

function getRooms(){
	console.log("trying to get rooms");
	console.log(`${serverUrl}/room/list`);
	$.getJSON(`${serverUrl}/room/list`,
	function(response) {
		console.log(response);
		for (var i = 0; i < response.data.rooms.length; i++){
			room = getRoomInfo(response.data.rooms[i]);
			while (! room) { }
			$('#tbl-roomlist').append('<tr><th id="tbl-rooms-' + i + '-id" scope="row">' + room.roomID + '</th><td id="tbl-rooms-' + i + '-features">' + '<button id="tbl-btn-rooms-' + i + '-features" class="btn"><i class="fa fa-eye"></i></button>' + '</td><td id="tbl-rooms-' + i + '-beds">' + "" + '</td><td id="tbl-rooms-' + i + '-price">' + room.basePrice + '</td><td id="tbl-rooms-' + i + '-book"><button id="tbl-btn-rooms-' + i + '-book" class="btn"><i class="fa fa-book"></i></button></td></tr>');
		}
	});
}
*/
function getRooms(){
	console.log("trying to get rooms");
	console.log(`${serverUrl}/room/list`);
	$.getJSON(`${serverUrl}/room/list`,
	function(response) {
		console.log(response);
		for (var i = 0; i < response.data.rooms.length; i++){
			console.log(`checking room ${response.data.rooms[i]}`);
			roomid = response.data.rooms[i];
			$.getJSON(`${serverUrl}/room/${roomid}`,
			function(response) {
				if (response.status.code == 200){
					room = response.data;

					// determine how many beds the room has
					bedfeature = room.features.filter(function(val) { return val.id === "1"; }); // returns the feature object with id 1 (beds)
					beds = bedfeature[0].amount;

					var price = Number(room.baseprice);
					for (var i = 0; i < room.features.length; i++){
						price += (Number(room.baseprice)*Number(room.features[i].pricemultiplier))-Number(room.baseprice);
					}

					price = round(price);

					// create table row
					$('#tbl-roomlist').append('<tr><th class="align-middle" id="tbl-rooms-' + i + '-id" scope="row">' + room.roomid + '</th><td class="align-middle" id="tbl-rooms-' + i + '-features">' + '<button id="tbl-btn-rooms-' + i + '-features" data-toggle="modal" data-target="#mod-features" class="btn"><i class="fa fa-eye"></i></button>' + '</td><td class="align-middle" id="tbl-rooms-' + i + '-beds">' + beds + '</td><td class="align-middle" id="tbl-rooms-' + i + '-price">' + price + ' €</td><td class="align-middle" id="tbl-rooms-' + i + '-book"><button id="tbl-btn-rooms-' + i + '-book" class="btn"><i class="fa fa-book"></i></button></td></tr>');
				} else {
					console.log("getting roominfo failed");
					console.log(response);
				}
			});	
		}
	});
}
/* 
	Implementation of the /room/<roomid> endpoint
*/
function getRoomInfo(roomid){
	console.log("getting room info for");
	console.log(roomid);
	var returndata;
	$.getJSON(`${serverUrl}/room/${roomid}`,
	function(response) {
		if (response.status.code == 200){
			console.log("success");
			return response.data;
		} else {
			console.log("getting roominfo failed");
			console.log(response);
		}
	});
}

/* 
	Convenience function to fill the room data from the server before updating
*/ 

function getRoomInfoUpdate(){
	/* disabled roomid input - very secure!*/
	$('#updateroomid').prop('disabled' ,true);

	$.getJSON(`${serverUrl}/room/`+ $('#updateroomid').val(),
	function(response) {
		$('#updateroomid').val(response.data.roomID);
		$('#coordinatestlx').val(response.data.coordinates.tlx);
		$('#coordinatestly').val(response.data.coordinates.tly);
		$('#coordinatesbrx').val(response.data.coordinates.brx);
		$('#coordinatesbry').val(response.data.coordinates.bry);
		$('#updatebaseprice').val(response.data.baseprice);
		for (var i = 0; i < response.data.features.length; i++){
			$('#updateroomfeatureslist').append('<tr><td><input id="updateroomfeatureid'+i+'" value="' + response.data.features[i].id + '" /></td>' + '<td><input id="updateroomfeaturename'+i+'" value="' + response.data.features[i].name + '" /></td>' + '<td><input id="updateroomfeaturepricemultiplier'+i+'" value="' + response.data.features[i].priceMultiplier + '" /></td>' + '<td><input id="updateroomfeatureamount'+i+'" value="' + response.data.features[i].amount + '" /></td>' + '</tr>');
		}
		});
}

/* 
	Implementation of the /room/update endpoint

*/

function updateRoomInfo(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	request.data.roomid=$('#updateroomid').val();
	request.data.coordinates.tlx=$('#updatecoordinatestlx').val();
	request.data.coordinates.tlx=$('#updatecoordinatestly').val();
	request.data.coordinates.tlx=$('#updatecoordinatesbrx').val();
	request.data.coordinates.tlx=$('#updatecoordinatesbry').val();
	request.data.baseprice=$('#updatebaseprice').val();

	request.data.features = [];

	for (var i = $('#updateroomfeatureslist tr').length-1; i > 0; i--){
		request.data.features.push({'id':$('#updateroomfeatureid'+i).val(), 'name':$('#updateroomfeaturename'+i).val(), 'priceMultiplier':$('#updateroomfeaturepricemultiplier'+i).val(), 'amount':$('#updateroomfeatureamount'+i).val()});
	}

	$.postJSON(`${serverUrl}/user/update`,
	request, 
	function(response) {
		alert(response.data.successful);
	});

	/* clear form */
	$('#updateroomid').val('');
	$('#updatecoordinatestlx').val('');
	$('#updatecoordinatestly').val('');
	$('#updatecoordinatesbrx').val('');
	$('#updatecoordinatesbry').val('');
	$('#updatebaseprice').val('');

	$('#updateroomfeatureslist').find("tr:gt(0)").remove(); //remove all tr elements greater than 0

	$('#updateroomid').prop('disabled' , false);
}

///////////////////////////////
/////// event listeners ///////
///////////////////////////////

$( document ).ready(function(){ //only run this script after the loading of the page finished


	// not yet correctly implemented functions
	$('#usergetinfo').click(getUserInfo); 	/* /user */

	$('#getroomlist').click(getRooms); 		/* /room/list */
	$('#checkroomidsubmit').click(getRoomInfo); /* /room/# */
	$('#updateroomidsubmit').click(updateRoomInfo); /* /room/update */
	$('#featurefillroominfo').click(getRoomInfoUpdate); /* helper */

	// integrated functions

	// event listeners for the functionality of the page
	$('#btn-login').click(login);			/* /user/auth */
	$('#btn-logout').click(logout);			/* /user/logout */
	$('#btn-register').click(register);		/* /user/register */
	$('#btn-settings').click(loadSettings);
	$('#btn-settings-update').click(userUpdate); /* /user/update */

	$('#tbl-roomlist tbody').on('click', 'button', function(){
		roomid = $(this).closest('tr').children()[0].innerHTML;
		displayFeatures(roomid);
	});

	// show hotel info in the footer
	getHotelInfo();							/* /hotel */

	// acquire info about the current user, if a SID is found
	getUserInfo();

	// show hidden navbar items depending on the logged in state
	showElementsbyState();
});