// seriously, fuck this language


// please change this to your server
var serverUrl = "http://localhost:8080"

var userId = 0;
var roleId = 0;
var loggedIn = 0;


const defaultRequest = {
	"auth": {
		"sid": null
	},
	"data": {
	}
};

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

		if (roleId > 1){
			$('#nav-settings').removeClass('d-none');
		}
		if (roleId > 2){
			$('#nav-manage').removeClass('d-none');
		}
		if (roleId > 3){
			$('#nav-admin').removeClass('d-none');
			$('#nav-debug').removeClass('d-none');
		}

		$('#btn-login-dropdown').addClass('d-none');
		$('#btn-logout').removeClass('d-none');
	}
}

function checkLoginState(){
	//TODO: define an endpoint to determine the valid state of a SID
}

// this is a function i found which corrects the missing headers
// for the $.post function. without application/json the server
// doesnt really know what to do with the data 
$.postJSON = function(url, data, callback) {
	return jQuery.ajax({
		'type': 'POST',
		'url': url,
		'contentType': 'application/json',
		'data': JSON.stringify(data),
		'dataType': 'json',
		'success': callback
	});
};

/*
	Implementation of the /hotel endpoint
*/

function getHotelInfo(){
	$.getJSON(`${serverUrl}/hotel`, '',
		function(response) {
			console.log(response);

			$('#cnt-hotelname').text(response.data.name);
			$('#cnt-contact').text(response.data.contact);
			$('#cnt-address').text(response.data.address);
			$('#cnt-description').text(response.data.description);

 		 });
}

/* 
	Implementation of the /user endpoint

	TODO: what happens if no user is logged in?
*/

function getUserInfo(){
	$.getJSON(`${serverUrl}/user`,
		function(response) {
			console.log(response);

			$('#userfirstName').text(response.data.firstName);
			$('#userlastName').text(response.data.lastName);
			$('#useremail').text(response.data.emailName);
			$('#userbirthdate').text(response.data.birthday);
			$('#useraddress').text(response.data.address);

 		 });
}

/*
	Implementation of the /user/auth endpoint
*/

function login(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');
	
	request.data = {
			"username": $('#frm-username').val(),
			"password": $('#frm-password').val()
		}
	$.postJSON(`${serverUrl}/user/auth`,
	request, 
	function(response) {
		if (Cookies.get('sid') == null) {
				Cookies.set('sid', response.auth.sid, { expires: 7, path: '' }); // 7 days
		}
	});
};

/*
	Implementation of the /user/logout endpoint
	TODO: make sure the server reacts properly in case an empty call comes along
*/

function logout(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');
	if (! request.auth.sid ){
		$.postJSON(`${serverUrl}/user/auth`,
		request, 
		function(response) {
			// no response
		});
	}
}

/*
	Implementation of the /user/register endpoint
*/

function userRegister(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	request.data.firstName=$('#registerfirstname').val();
	request.data.lastName=$('#registerlastname').val();
	request.data.email=$('#registeremail').val();
	request.data.birthdate=$('#registerbirthdate').val();
	request.data.address=$('#registeraddress').val();
	request.data.password=$('#registerpassword').val();

	$.postJSON(`${serverUrl}/user/register`,
	request, 
	function(response) {
		// no response
	});
}

/*
	Implementation of the /user/update endpoint
*/

function userUpdate(){
	var request = defaultRequest;
	request.auth.sid = Cookies.get('sid');

	request.data.firstName=$('#updatefirstname').val();
	request.data.lastName=$('#updatelastname').val();
	request.data.email=$('#updateemail').val();
	request.data.birthdate=$('#updatebirthdate').val();
	request.data.address=$('#updateaddress').val();
	request.data.password=$('#updatepassword').val();

	$.postJSON(`${serverUrl}/user/update`,
	request, 
	function(response) {
		// no response
	});
}


/* 
	Implementation of the /room/list endpoint
*/

function getRooms(){
	$.getJSON(`${serverUrl}/room/list`,
	function(response) {
		for (var i = 0; i < response.data.rooms.length; i++){
			$('#roomlist').append('<tr><td>' + response.data.rooms[i] + '</td></tr>');
		}
		});
}

/* 
	Implementation of the /room/<roomid> endpoint
*/
function getRoomInfo(){
	$.getJSON(`${serverUrl}/room/`+ $('#roomidinput').val(),
	function(response) {
		$('#roomid').text(response.data.roomID);
		$('#coordinatestlx').text(response.data.coordinates.tlx);
		$('#coordinatestly').text(response.data.coordinates.tly);
		$('#coordinatesbrx').text(response.data.coordinates.brx);
		$('#coordinatesbry').text(response.data.coordinates.bry);
		$('#baseprice').text(response.data.baseprice);
		for (var i = 0; i < response.data.features.length; i++){
			$('#roomlist').append('<tr><td>' + response.data.features[i].id + '</td><td>'+ response.data.features[i].name + '</td><td>'+ response.data.features[i].priceMultiplier+ '</td><td>'+ response.data.features[i].amount +'</td></tr>');
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

	request.data.roomID=$('#updateroomid').val();
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

$( document ).ready(function(){ //only run this script after the loading of the page finished


	// not yet correctly implemented functions
	$('#usergetinfo').click(getUserInfo); 	/* /user */
	$('#update').click(userUpdate); 		/* /user/update */
	$('#register').click(userRegister); 	/* /user/register */

	$('#getroomlist').click(getRooms); 		/* /room/list */
	$('#checkroomidsubmit').click(getRoomInfo); /* /room/# */
	$('#updateroomidsubmit').click(updateRoomInfo); /* /room/update */
	$('#featurefillroominfo').click(getRoomInfoUpdate); /* helper */
	


	// integrated functions

	// event listeners for the functionality of the page
	$('#btn-login').click(login);			/* /user/auth */
	$('#btn-logout').click(logout);			/* /user/logout */

	// show hotel info in the footer
	getHotelInfo();							/* /hotel */

	// show hidden navbar items depending on the logged in state
	showElementsbyState();
});