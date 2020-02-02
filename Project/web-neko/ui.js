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
		request.auth.sid = Cookies.get('sid');
		
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

	$('#usergetinfo').click(getUserInfo); 	/* /user */
	$('#login').click(login); 				/* /user/auth */
	$('#logout').click(logout); 			/* /user/logout */ 
	$('#update').click(userUpdate); 		/* /user/update */
	$('#register').click(userRegister); 	/* /user/register */

	$('#getroomlist').click(getRooms); 		/* /room/list */
	$('#checkroomidsubmit').click(getRoomInfo); /* /room/# */
	$('#updateroomidsubmit').click(updateRoomInfo); /* /room/update */
	$('#featurefillroominfo').click(getRoomInfoUpdate); /* helper */

	$('#hotelgetinfo').click(getHotelInfo); /* /hotel */
});