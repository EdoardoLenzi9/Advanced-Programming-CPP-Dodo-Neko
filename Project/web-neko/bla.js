// seriously, fuck this language

$( document ).ready(function(){ //only run this script after the loading of the page finished

	// please change this to your server
	var serverUrl = "http://192.168.178.33:8081"

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
	function checkRoom(){
		var roomNumber = $('#checkRoomNumber').val();
		console.log("checking room for:" + roomNumber);
		
		var request = defaultRequest;
		request.data = {
		    	"roomID": roomNumber
		    }
		$.postJSON(`${serverUrl}/book/check`,
		request, 
		function( data ) {
			if (parseFloat(data.data.free) > 0){
				$('#checkRoomResponse').text(data.data.roomID + " is occupied"); 
			} else {
				$('#checkRoomResponse').text(data.data.roomID + " is free"); 
			}
		});
	};

	
	$('#checkRoomSubmit').click(checkRoom);
});