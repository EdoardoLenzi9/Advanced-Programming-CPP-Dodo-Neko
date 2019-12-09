function login () {

	$("#password")

	httpPostAsync("/login", null, null, function(body){
		debugger
		alert(body);
	});	
}