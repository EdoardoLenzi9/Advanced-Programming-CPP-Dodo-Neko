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

		if (user.roleid >= 1){
			$('#nav-settings').removeClass('d-none');
			$('#nav-manage').removeClass('d-none');
		}
		if (user.roleid >= 2){
			// placeholder
		}
		if (user.roleid >= 3){
			$('#nav-admin').removeClass('d-none');
			$('#nav-debug').removeClass('d-none');
		}

		$('#btn-login-dropdown').addClass('d-none');
		$('#btn-logout').removeClass('d-none');
		$('#btn-settings').removeClass('d-none');
	} else {
		$('#nav-manage').addClass('d-none');
		$('#nav-admin').addClass('d-none');
		$('#nav-debug').addClass('d-none');
		$('#nav-settings').addClass('d-none');
		$('#btn-logout').addClass('d-none');
		$('#btn-login-dropdown').removeClass('d-none');
		$('#nav-register').removeClass('d-none');
	}

	if ( user.roleid > 1) {
		$('#tbl-bookingslist-col-user').removeClass('d-none');
		$('#tbl-bookingslist tr td').each( function(){
			$('td[id*="user"]').removeClass('d-none');
		});
		$('#tbl-bookingslist-col-confirm').removeClass('d-none');
		$('#tbl-bookingslist tr td').each( function(){
			$('td[id*="confirm"]').removeClass('d-none');
		});
	} else {
		$('#tbl-bookingslist-col-user').addClass('d-none');
		$('#tbl-bookingslist tr td').each( function(){
			$('td[id*="user"]').addClass('d-none');
		});
		$('#tbl-bookingslist-col-confirm').addClass('d-none');
		$('#tbl-bookingslist tr td').each( function(){
			$('td[id*="confirm"]').addClass('d-none');
		});
	}
}

function makeAlert(head, text, type, classes){
	return '<div class="alert ' + type + ' ' + classes + ' alert-dismissible fade show" role="alert"> <strong>'+ head + '</strong> ' + text + ' <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button></div>'
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
		'error': function(){ 
			$('header').append(makeAlert("Holy guacamole!", "The API seems to have failed!", "alert-danger", "mt-2"));
		},
		'timeout': 3000
	});
};

function loadSettings(){
	getUserInfo();
	$('#frm-update-email').val(user.email);
	$('#frm-update-firstname').val(user.firstname);
	$('#frm-update-lastname').val(user.lastname);
	$('#frm-update-address').val(user.address);
	birthday = new Date(user.birthday*1000);
	// this language is beyond retarded.
	year = birthday.getFullYear();
	month = birthday.getMonth()+1;
	day = birthday.getDate();

	$('#frm-update-birthday').val(`${year}-${month}-${day}`);
	$('#frm-update-userid').val(user.userid);
	$('#frm-update-roleid').val(user.roleid);

	if (user.roleid > 1){
		$('#frm-update-userid').attr('disabled', false);
		$('#frm-update-roleid').attr('disabled', false);
	}
}

function loadMainPage(){
	window.location = window.location.origin;
}

function replaceCurrency(){
	$('.currency').each(function(text){
		this.innerHTML = ' <i class="fa fa-btc"></i>';
	});

}

/*
	Implementation of the /hotel endpoint
*/

function getHotelInfo(){
	$.getJSON(`${serverUrl}/hotel`,
		function(response) {
			if (response.status.code == 200 ){
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
			if ( response.status.code == 200 ){
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
				Cookies.remove('sid');
				loggedIn = 0;
				console.log("acquiring user info failed");
				console.log(response);
				showElementsbyState()
			}
		});
	} else {
		loggedIn = 0;
		Cookies.remove('sid');
		showElementsbyState()
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

function deleteBooking(bookid){
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	request.data.bookid = Number(bookid.replace("book-", ""));

	if ( request.auth.sid ) {
		$.postJSON(`${serverUrl}/book/delete`,
		request,
		function(response) {
			console.log("callback running");
			if ( response.status.code == 200 ){
				$('#mod-delete-booking').modal('hide');
				getBookings();
			} else {
				alert("deleting the booking was refused");
			}
		});
	} else {
		alert("not logged in");
	}

}

function confirmBooking(bookid){
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	request.data.bookid = Number(bookid.replace("book-", ""));

	if ( request.auth.sid ) {
		$.postJSON(`${serverUrl}/book/confirmpayment`,
		request,
		function(response) {
			console.log("callback running");
			if ( response.status.code == 200 ){
				$('#mod-confirm-booking').modal('hide');
				getBookings();
			} else {
				alert("confirming the booking was refused");
			}
		});
	} else {
		alert("not logged in");
	}

}

function displayBooking(roomid){
	getUserInfo();
	if (loggedIn == 1) {
		$('#mod-booking-guest').addClass('d-none');
		$('#mod-booking-confirmed').addClass('d-none');
		$('#mod-booking-user').removeClass('d-none');
		$('#btn-sendbooking').removeClass('d-none');
		$('#btn-cancelbooking').removeClass('d-none');
		$('#btn-closebooking').addClass('d-none');

		roomnumber = $(`#tbl-${roomid}-number`).text();
		price = Number($(`#tbl-${roomid}-price-raw`).text());
		arrival = $('#frm-arrival').val();
		departure = $('#frm-departure').val();

		$('#spn-roomid').text(roomid);
		$('#spn-roomcost').text(price);
		$('#spn-roomnumber').text(roomnumber);
		$('#spn-arrival').text(arrival);
		$('#spn-departure').text(departure);

		arrival = new Date(arrival).getTime();
		departure = new Date(departure).getTime();

		totaldays = Number((departure-arrival)/1000/86400);

		$('#spn-totaldays').text(totaldays);
		$('#spn-finalprice').text(price*totaldays);

		
	} else {
		$('#mod-booking-user').addClass('d-none');
		$('#mod-booking-confirmed').addClass('d-none');
		$('#mod-booking-guest').removeClass('d-none');
	}
}

function requestBooking(){
	getUserInfo();
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;

	request.auth.sid = Cookies.get('sid');

	roomid = Number($('#spn-roomid').text().replace("room-", ""));
	arrival = Math.floor((new Date($('#spn-arrival').text())).getTime()/1000);
	departure = Math.floor((new Date($('#spn-departure').text())).getTime()/1000);

	request.data.roomid = roomid;
	request.data.arrival = arrival;
	request.data.departure = departure;

	$.postJSON(`${serverUrl}/book/create`,
	request, 
	function(response) {
		if (response.status.code == 200){	
			$('#mod-booking-user').addClass('d-none');
			$('#mod-booking-guest').addClass('d-none');
			$('#mod-booking-confirmed').removeClass('d-none');
			$('#btn-sendbooking').addClass('d-none');
			$('#btn-cancelbooking').addClass('d-none');
			$('#btn-closebooking').removeClass('d-none');
			getRooms();
		} else {
			$('#lrt-booking-failed').show();
			console.log(response);
		}
	});
}

/*
	Implementation of the /user/auth endpoint
*/

function login(){
	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	Cookies.remove('sid');
	// yes i get this is redundant
	request.auth.sid = "";
	
	request.data = {
			"email": $('#frm-username').val(),
			"password": $('#frm-password').val()
		}
	$.postJSON(`${serverUrl}/user/auth`,
	request, 
	function(response) {
		console.log("callback for login running");
		if (response.status.code == 200) {
			console.log("authentication successful");
			Cookies.set('sid', response.data.sid, { expires: 7, path: '' }); // 7 days	
			getUserInfo();
		} else if (response.status.code == 401) {
			$('#div-login-dropdown').prepend(makeAlert("Login failed!", "Try again.", "alert-danger", ""));
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
		$.postJSON(`${serverUrl}/user/logout`,
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

	var empty = 0;

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
	request.data.birthdate=Math.floor(new Date($('#frm-birthday').val()).getTime()/1000);

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
				//TODO: needs a nice way to tell the user
				alert("registering was successful. please log in.");
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

	request.data.firstname = $('#frm-update-firstname').val();
	request.data.lastname = $('#frm-update-lastname').val();
	request.data.email = $('#frm-update-email').val();
	request.data.birthdate = (new Date($('#frm-update-birthday').val()).getTime())/1000;
	request.data.address = $('#frm-update-address').val();
	request.data.password = $('#frm-update-password').val();
	request.data.userid = Number($('#frm-update-userid').val());
	request.data.roleid = Number($('#frm-update-roleid').val());

	$.postJSON(`${serverUrl}/user/update`,
	request, 
	function(response) {
		if (response.status.code == 200){
			$('#mod-settings').modal('hide');
			if ($('#tbl-userlist').length > 0){
				getUsers();
			}
		} else {
			alert("something went wrong...");
			console.log(response);
		}
	});
}

function deleteUser(userid){
	getUserInfo();

	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	userid = userid.replace("user-", "");
	request.data.userid = Number(userid);

	$.postJSON(`${serverUrl}/user/delete`,
	request, 
	function(response) {
		if (response.status.code == 200){
			$('#mod-delete-user').modal('hide');
		} else {
			alert("something went wrong...");
			console.log(response);
		}
	});
}

function loadForeignUserSettings(userid){
	getUserInfo();

	email = $(`#tbl-${userid}-email`).text();
	firstname = $(`#tbl-${userid}-firstname`).text();
	lastname = $(`#tbl-${userid}-lastname`).text();
	address = $(`#tbl-${userid}-address`).text();
	birthday = $(`#tbl-${userid}-birthday`).text();
	roleid = $(`#tbl-${userid}-roleid`).text();

	$('#frm-update-email').val(email);
	$('#frm-update-firstname').val(firstname);
	$('#frm-update-lastname').val(lastname);
	$('#frm-update-address').val(address);
	$('#frm-update-birthday').val(birthday);
	$('#frm-update-userid').val(userid.replace("user-", ""));
	$('#frm-update-roleid').val(roleid);

	if (user.roleid > 1){
		$('#frm-update-userid').attr('disabled', false);
		$('#frm-update-roleid').attr('disabled', false);
	}
}



function getBookings(){

	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	$('#tbl-bookingslist tbody tr').each (function (val) { $(this).remove(); });

	$.postJSON(`${serverUrl}/book/list`,
	request,
	function(response) {
		if (response.status.code == 200){
			if (response.data.bookings != null){
				bookings = response.data.bookings;

				for (var i = 0; i < bookings.length; i++){
					roomnumber = bookings[i].room.roomnumber;
					arrival = bookings[i].arrival;
					departure = bookings[i].departure;
					price = bookings[i].price;
					paid = bookings[i].paid;
					userid = bookings[i].user.email;
					bookid = bookings[i].bookid;

					arrival = (new Date(arrival*1000));

					// this language is beyond retarded.
					year = arrival.getFullYear();
					month = arrival.getMonth()+1;
					day = arrival.getDate();

					arrival = `${year}-${month}-${day}`;

					departure = (new Date(departure*1000));

					year = departure.getFullYear();
					month = departure.getMonth()+1;
					day = departure.getDate();

					departure = `${year}-${month}-${day}`;


					$('#tbl-bookingslist').append('<tr id="book-'+ bookid + '"><td id="tbl-book-' + bookid + '-number" class="align-middle">' + roomnumber + '</td><td id="tbl-book-'+ bookid + '-arrival" class="align-middle">' + arrival + '</td><td id="tbl-book-' + bookid + '-departure" class="align-middle">' + departure + '</td><td id="tbl-book-' + bookid +'-price" class="align-middle"><span id="tbl-book-' + bookid + '-price-raw">' + price + '</span><span class="currency"></span></td><td id="tbl-book-' + bookid + '-paid" class="align-middle"><i id="tbl-icn-book-' + bookid + '-paid-check" class="fa fa-check d-none"></i><i id="tbl-icn-book-' + bookid + '-paid-false" class="fa fa-times"></i></td><td id="tbl-book-' + bookid + '-user" class="d-none align-middle">'+ userid + '</td><td id="tbl-book-' + bookid + '-delete" class="align-middle"><button id="tbl-btn-book-' + bookid + '-delete" data-toggle="modal" data-target="#mod-delete-booking" class="btn"><i class="fa fa-trash"></i></button></td><td id="tbl-book-' + bookid + '-confirm" class="align-middle d-none"><button id="tbl-btn-book-' + bookid + '-confirm" data-toggle="modal" data-target="#mod-confirm-booking" class="btn"><i class="fa fa-check"></i></button></td></tr>');

					if ( paid ) {
						$(`#tbl-icn-book-${bookid}-paid-false`).addClass("d-none");
						$(`#tbl-icn-book-${bookid}-paid-check`).removeClass("d-none");
						$(`#tbl-btn-book-${bookid}-delete`).attr("disabled", true);
						$(`#tbl-btn-book-${bookid}-confirm`).attr("disabled", true);
					}
				} 
				replaceCurrency();
				showElementsbyState();
			} else {
				$('#div-showbookings').append(makeAlert("Hey!", "Book more rooms!", "alert-warning" , ""));
			}
		} else {
			alert("getting the room list failed due to unknown reasons. check log.");
			console.log(response);
		}
		
	});

}

function getUsers(){

	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	$('#tbl-userlist tbody tr').each (function (val) { $(this).remove(); });

	$.postJSON(`${serverUrl}/user/list`,
	request,
	function(response) {
		if (response.status.code == 200){
			if (response.data.users != null){
				users = response.data.users;

				for (var i = 0; i < users.length; i++){

					userid = users[i].userid;
					roleid = users[i].roleid;
					firstname = users[i].firstname;
					lastname = users[i].lastname;
					email = users[i].email;
					birthday = users[i].birthdate;
					address = users[i].address;

					birthday = (new Date(birthday*1000));

					// this language is beyond retarded.
					year = birthday.getFullYear();
					month = birthday.getMonth()+1;
					day = birthday.getDate();

					birthday = `${year}-${month}-${day}`;

					console.log(`adding user ${userid}, email ${email}`);

					$('#tbl-userlist').append('<tr id="user-'+ userid + '"><td id="tbl-user-' + userid + '-number" class="align-middle">' + userid + '</td><td id="tbl-user-'+ userid + '-firstname" class="align-middle">' + firstname + '</td><td id="tbl-user-' + userid + '-lastname" class="align-middle">' + lastname + '</td><td id="tbl-user-' + userid +'-email" class="align-middle">'+ email + '</td><td id="tbl-user-' + userid + '-birthday" class="align-middle">' + birthday +'</td><td id="tbl-user-' + userid + '-address" class="align-middle">'+ address + '</td><td id="tbl-user-' + userid + '-role" class="align-middle">' + roleid + '</td><td id="tbl-user-' + userid + '-edit" class="align-middle"><button id="tbl-btn-user-' + userid + '-edit" data-toggle="modal" data-target="#mod-settings" class="btn"><i class="fa fa-edit"></i></button></td><td id="tbl-user-' + userid + '-delete" class="align-middle"><button id="tbl-btn-user-' + userid + '-delete" data-toggle="modal" data-target="#mod-delete-user" class="btn"><i class="fa fa-trash"></i></button></td></tr>');
				} 
			} else {
				$('#div-showusers').append(makeAlert("Hey!", "Add more users!", "alert-warning" , ""));
			}
		} else {
			alert("getting the room list failed due to unknown reasons. check log.");
			console.log(response);
		}
		
	});

}


function getRooms(){

	defaultRequest.data = {};
	defaultRequest.auth.sid = {};
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

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
			if (response.data.rooms != null){
				rooms = response.data.rooms;
				for (var i = 0; i < rooms.length; i++){
					room = rooms[i];
					console.log(`${i}/${rooms.length}: checking room ${room.roomid}`);

					roomid = room.roomid;
					roomnumber = room.roomnumber;
					features = rooms[i].features;
					price = Number(features.filter(feature => feature.id == '1')[0].price);
					console.log(price);
					beds = features.filter(feature => feature.id == '2')[0].amount;
					
					for (var j = 0; j < features.length; j++){
						if (features[j].id != 1){
							price += (Number(features[j].amount)*Number(features[j].price));
						}
					}

					price = round(price);

					$('#tbl-roomlist').append('<tr id="room-'+ roomid +'"><th class="align-middle" id="tbl-room-' + roomid + '-number" scope="row">' + roomnumber + '</th><td class="align-middle" id="tbl-room-' + roomid + '-features">' + '<button id="tbl-btn-room-' + roomid + '-features" data-toggle="modal" data-target="#mod-features" class="btn"><i class="fa fa-eye"></i></button>' + '</td><td class="align-middle" id="tbl-room-' + roomid + '-beds">' + beds + '</td><td class="align-middle" id="tbl-room-' + roomid + '-price"><span id="tbl-room-' + roomid + '-price-raw">' + price + '</span><span class="currency"></span></td><td class="align-middle" id="tbl-room-' + roomid + '-book"><button id="tbl-btn-room-' + roomid + '-book" data-toggle="modal" data-target="#mod-booking" class="btn"><i class="fa fa-book"></i></button></td></tr>');
				}
				replaceCurrency();

			} else {
			$('#div-showrooms').append(makeAlert("Sorry!", "No rooms are available during the selected timespan.", "alert-warning" , ""));
			}
		} else {
			alert("getting the room list failed due to unknown reasons. check log.");
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
	$('#btn-sendbooking').click(function(event){
		requestBooking()
	});

	// listener for dynamic table content of the booking page, feature button
	$('#tbl-roomlist tbody').on('click', 'button[id*="features"]', function(){
		roomid = $(this).closest('tr').children()[0].innerHTML;
		displayFeatures(roomid);
	});

	$('#tbl-roomlist tbody').on('click', 'button[id*="book"]', function(){
		roomid = $(this).closest('tr').prop('id');
		displayBooking(roomid);
	});

	$('#tbl-bookingslist tbody').on('click', 'button[id*="delete"]', function(){
		bookid = $(this).closest('tr').prop('id');
		$('#mod-delete-booking-bookid').text(bookid);
	});

	$('#mod-delete-booking').on('click', 'button[id*="delete-booking-yes"]', function(){
		bookid = $('#mod-delete-booking-bookid').text();
		deleteBooking(bookid);
	});

	$('#tbl-bookingslist tbody').on('click', 'button[id*="confirm"]', function(){
		bookid = $(this).closest('tr').prop('id');
		$('#mod-confirm-booking-bookid').text(bookid);
	});

	$('#mod-confirm-booking').on('click', 'button[id*="confirm-yes"]', function(){
		bookid = $('#mod-confirm-booking-bookid').text();
		confirmBooking(bookid);
	});

	$('#tbl-userlist tbody').on('click', 'button[id*="delete"]', function(){
		userid = $(this).closest('tr').prop('id');
		$('#mod-delete-user-userid').text(userid);
	});

	$('#mod-delete-user').on('click', 'button[id*="delete-user-yes"]', function(){
		userid = $('#mod-delete-user-userid').text();
		deleteUser(userid);
	});

	$('#tbl-userlist tbody').on('click', 'button[id*="edit"]', function(){
		userid = $(this).closest('tr').prop('id');
		loadForeignUserSettings(userid); //this re-uses the settings modal
	});

	/*
	// listener for dynamic table content of the booking page, book button
	$('#tbl-roomlist tbody').on('click', 'button', function(){
		roomid = $(this).closest('tr').children()[0].innerHTML;
		displayFeatures(roomid);
	});
	*/
	// replace currency
	replaceCurrency();

	// show hotel info in the footer
	getHotelInfo();

	// acquire info about the current user, if a SID is found
	getUserInfo();

	// show hidden navbar items depending on the logged in state
	//showElementsbyState();
});