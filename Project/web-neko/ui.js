// seriously, fuck this language

$( document ).ready(function(){ //only run this script after the loading of the page finished

	// please change this to your server
	var serverUrl = "http://localhost:8080"

	const defaultRequest = {
	    "auth": {
	        "sid": null
	    },
	    "data": {
	    }
	};

	


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
	test function 1, just here for my reference
	*/
	// function listUsers(){
	//     $.getJSON(`${serverUrl}/listUsers`,
	//     function(data) {
	//     	console.log(data);
	//     	$('#userdata').empty();
	//     	$('#userdata').append('<tr><td> Name </td><td> Profession </td></tr>');
	//         for (var i = 0; i < data.length; i++){
	//         	console.log(i + " is: " + data[i]);
	//         	$('#userdata').append('<tr><td>'+ data[i].name +'</td><td>'+ data[i].profession +'</td></tr>');
	//         }
 	//      });
 	//  };

 	/*

	Implementation of the checkroom endpoint, incomplete
	TODO

	POST Request: 

	{
	    "auth": {
	        "sid": null
	    },
	    "data": {
	        "roomID":"<num>"
	    }
	}

	Expected Response:

	{
	    "status": {
	        "code": "<num>",
	        "description": "<something>"
	    },
	    "data": {
	           "roomID: "<num>"
   			   "free": "<num>" 
	    }
	}	

	Note: roomID should be the same as sent.
		  occupied rooms have 0, every other value is taken as free
		  description and status code are currently ignored

	*/
/*	function checkRoom(){
		var roomNumber = $('#checkRoomNumber').val();
		console.log("checking room for:" + roomNumber);
		
		var request = defaultRequest;
		request.data = {
		    	"roomID": roomNumber
		    }
		$.postJSON(`${serverUrl}/book/check`,
		request, 
		function(response) {
			if (parseFloat(response.data.free) > 0){
				$('#checkRoomResponse').text(response.data.roomID + " is occupied"); 
			} else {
				$('#checkRoomResponse').text(response.data.roomID + " is free"); 
			}
		});
	};*/

	/*
		Implementation of the /hotel endpoint
	*/

	function getHotelInfo(){
	    $.getJSON(`${serverUrl}/hotel`, '',
		    function(response) {
		    	console.log(response);

				$('#hotelname').text(response.data.name);
				$('#hotelcontact').text(response.data.contact);
				$('#hoteladdress').text(response.data.address);
				$('#hoteldescription').text(response.data.description);

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
		var roomNumber = $('#checkRoomNumber').val();
		var request = defaultRequest;
		
		request.data = {
		    	"username": $('#username').val(),
		    	"password": $('#password').val()
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
	*/

	function logout(){
		var request = defaultRequest;
		request.auth.sid = Cookies.get('sid');

		$.postJSON(`${serverUrl}/user/auth`,
		request, 
		function(response) {
			// no response
		});
	}

	/*
		Implementation of the /user/register endpoint
	*/
	
	function userRegister(){
		var request = defaultRequest;

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
		Implementation of the /user/register endpoint
	*/
	
	function userUpdate(){
		var request = defaultRequest;

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
	    	$('#coordinatestlx').text();
	    	$('#coordinatestly').text();
	    	$('#coordinatesbrx').text();
	    	$('#coordinatesbry').text();
	    	$('#baseprice').text();
	    	for (var i = 0; i < response.data.features.length; i++){
	    		$('#roomlist').append('<tr><td>' + response.data.features.feature[i].id + '</td><td>'+ response.data.features.feature[i].name + '</td><td>'+ response.data.features.feature[i].priceMultiplier+ '</td><td>'+ response.data.features.feature[i].amount +'</td></tr>');
	    	}
 		});
	}



	$('#update').click(userUpdate);
	$('#register').click(userRegister);
	$('#login').click(login);
	$('#getroomlist').click(getRooms);
	$('#logout').click(logout);
	$('#hotelgetinfo').click(getHotelInfo);
	$('#usergetinfo').click(getUserInfo);
	//$('#checkRoomSubmit').click(checkRoom);
});