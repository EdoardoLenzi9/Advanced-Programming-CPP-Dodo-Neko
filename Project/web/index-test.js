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
	Note: roomID should be the same as sent.
		  occupied rooms have 0, every other value is taken as free
		  description and status code are currently ignored

	*/
	function checkRoom(){
		var roomNumber = $('#checkRoomNumber').val();
		console.log("checking room for:" + roomNumber);
		
		var request = defaultRequest;
		request.data = {
		    	"roomID": roomNumber
		    }
		$.postJSON(`${serverUrl}/room/check`,
		request, 
		function( data ) {
			debugger;
			if (parseFloat(data.free) > 0){
				$('#checkRoomResponse').text(roomNumber + " is occupied"); 
			} else {
				$('#checkRoomResponse').text(roomNumber + " is free"); 
			}
		});
	};

	
	$('#checkRoomSubmit').click(checkRoom);
});