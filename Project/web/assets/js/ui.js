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

var rooms = {};

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
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
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

function displayFeatures(roomnumber){
features.filter(feature => feature.id == '2')[0].amount;


	$('#tbl-featurelist tbody tr').each (function (val) { $(this).remove(); })

	features = rooms.filter(room => room.roomnumber == roomnumber)[0].features;

	for (var i = 0; i < features.length; i++) {
		if (features[i].id != 1){
			$('#tbl-featurelist').append('<tr name="featurerow"><td>' + features[i].name + '</td><td>' + features[i].amount + '</td></tr>');
		}
	}

}

function displayBooking(roomnumber){
	getUserInfo();
	if (loggedIn == 1) {
		console.log(loggedIn);
		$('#mod-booking-guest').addClass('d-none');
		$('#mod-booking-confirmed').addClass('d-none');
		$('#mod-booking-user').removeClass('d-none');
		$('#btn-sendbooking').removeClass('d-none');
		$('#btn-cancelbooking').removeClass('d-none');
		$('#btn-closebooking').addClass('d-none');

		$('#spn-roomnumber').
		$('#spn-arrival')
		$('#spn-departure')


		
	} else {
		console.log(loggedIn);
		$('#mod-booking-user').addClass('d-none');
		$('#mod-booking-confirmed').addClass('d-none');
		$('#mod-booking-guest').removeClass('d-none');
	}
}

function requestBooking(){

	$('#mod-booking-user').addClass('d-none');
	$('#mod-booking-guest').addClass('d-none');
	$('#mod-booking-confirmed').removeClass('d-none');

}

/*
	Implementation of the /user/auth endpoint
*/

function login(){
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
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
			//loadMainPage();
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
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
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
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
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

	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
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
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	//TODO: make sure the date isnt a negative timespan
	request.data.startdate = Math.floor(new Date($('#frm-arrival').val()).getTime()/1000);
	request.data.enddate = Math.floor(new Date($('#frm-departure').val()).getTime()/1000);

	if (!request.data.startdate){
		alert("Please enter a valid arrival date.");
		return;
	}

	if (!request.data.enddate){
		alert("Please enter a valid departure date.");
		return;
	}

	if (Number(request.data.startdate) < new Date().getTime()/1000){
		alert("No Timetravellers allowed in our hotel! Arrival date is in the past.");
		return;
	}

	if (Number(request.data.enddate) < new Date().getTime()/1000){
		alert("No Timetravellers allowed in our hotel! Departure date is in the past.");
		return;
	}

	if (Number(request.data.enddate)-Number(request.data.startdate) < 86400){
		alert("You need to stay at least a day.");
		return; 
	}

	$('#div-showrooms').removeClass('d-none')

	$('#tbl-roomlist tbody tr').each (function (val) { $(this).remove(); })

	// TODO: dont send request if no dates 
	$.postJSON(`${serverUrl}/room/list`,
	request,
	function(response) {
		if (response.status.code == 200){
			//exporting to global namespace as a workaround
			rooms = response.data.rooms;
			console.log(response.data.rooms.length);
			for (var i = 0; i < response.data.rooms.length; i++){
				room = response.data.rooms[i];
				console.log(`${i}/${response.data.rooms.length}: checking room ${room.roomid}`);

				roomid = room.roomid;
				roomnumber = room.roomnumber;
				features = response.data.rooms[i].features;
				price = Number(features.filter(feature => feature.id == '1')[0].price);
				console.log(price);
				beds = features.filter(feature => feature.id == '2')[0].amount;
				
				for (var j = 0; j < features.length; j++){
					if (features[j].id != 1){
						price += (Number(features[j].amount)*Number(features[j].price));
					}
				}

				price = round(price);

				// create table row
				$('#tbl-roomlist').append('<tr><th class="align-middle" id="tbl-rooms-' + roomid + '-id" scope="row">' + room.roomnumber + '</th><td class="align-middle" id="tbl-rooms-' + roomid + '-features">' + '<button id="tbl-btn-rooms-' + roomid + '-features" data-toggle="modal" data-target="#mod-features" class="btn"><i class="fa fa-eye"></i></button>' + '</td><td class="align-middle" id="tbl-rooms-' + roomid + '-beds">' + beds + '</td><td class="align-middle" id="tbl-rooms-' + roomid + '-price">' + price + ' €</td><td class="align-middle" id="tbl-rooms-' + roomid + '-book"><button id="tbl-btn-rooms-' + roomid + '-book" data-toggle="modal" data-target="#mod-booking" class="btn"><i class="fa fa-book"></i></button></td></tr>');
			}
		} else {
			console.log("getting rooms failed");
			console.log(response);
		}
	});
}

///////////////////////////////
/////// event listeners ///////
///////////////////////////////

$( document ).ready(function(){ //only run this script after the loading of the page finished

	// integrated functions

	// event listeners for the functionality of the page
	$('#btn-login').click(login);			/* /user/auth */
	$('#btn-logout').click(logout);			/* /user/logout */
	$('#btn-register').click(register);		/* /user/register */
	$('#btn-settings').click(loadSettings);
	$('#btn-settings-update').click(userUpdate); /* /user/update */
	$('#btn-getrooms').click(getRooms);
	$('#btn-sendbooking').click(requestBooking);

	

	// listener for dynamic table content of the booking page, feature button
	$('#tbl-roomlist tbody').on('click', 'button[id*="features"]', function(){
		roomnumber = $(this).closest('tr').children()[0].innerHTML;
		displayFeatures(roomnumber);

	});

	$('#tbl-roomlist tbody').on('click', 'button[id*="book"]', function(){

		roomnumber = $(this).closest('tr').children()[0].innerHTML;
		displayBooking(roomnumber);

	});
	/*
	// listener for dynamic table content of the booking page, book button
	$('#tbl-roomlist tbody').on('click', 'button', function(){
		roomid = $(this).closest('tr').children()[0].innerHTML;
		displayFeatures(roomid);
	});
	*/
	// show hotel info in the footer
	getHotelInfo();							/* /hotel */

	// acquire info about the current user, if a SID is found
	//getUserInfo();

	// show hidden navbar items depending on the logged in state
	showElementsbyState();
});