var scene, camera, controls, renderer, group, raycaster, mouseVector;



function Init(){
	scene = new THREE.Scene();
	camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
	camera.position.z = 5;
	InitControl();

	LoadArchitecture("mesh.json");
	raycaster = new THREE.Raycaster();
	mouseVector = new THREE.Vector3();

	renderer = new THREE.WebGLRenderer();
	renderer.setSize(window.innerWidth, window.innerHeight);
	document.body.appendChild(renderer.domElement)

	window.addEventListener( 'resize', onWindowResize, false );
	window.addEventListener( "mousemove", onDocumentMouseMove, false );
}

function onWindowResize() {
	camera.aspect = window.innerWidth / window.innerHeight;
	camera.updateProjectionMatrix();
	renderer.setSize( window.innerWidth, window.innerHeight );
}

function Render(){
	// Inserisco la chiamata ricorsiva nel loop stesso del web browser che comunque fa un render del codice
	requestAnimationFrame(Render); // Render();
	controls.update();
	renderer.render(scene, camera);
}

Init();
Render();


/*
* Init Camera Control
*/
function InitControl(minDistance = 100, maxDistance=500){

	controls = new THREE.OrbitControls( camera );
	controls.enableDamping = true; // an animation loop is required when either damping or auto-rotation are enabled
	controls.dampingFactor = 0.25;
	controls.screenSpacePanning = false;
	controls.minDistance = minDistance;
	controls.maxDistance = maxDistance;
	controls.maxPolarAngle = Math.PI / 2;	
}


/*
* deserialize the json content and setup each component defined
*/ 
function LoadArchitecture( file ) {
	group = new THREE.Group();
	scene.add(group);

	Read( file, function( content ){
		architecture = JSON.parse(content);   
		architecture.forEach(function(component){
			SetupMesh(component);
		});
	})
}


/*
* Given a component definition loads the component and add it to the scene
*/ 
function SetupMesh( parameters ) {
	debugger;
	var boxGeometry = new THREE.CubeGeometry(parameters.x, parameters.y, parameters.z); // larghezza, altezza, profondita'
	var boxMaterial = new THREE.MeshBasicMaterial({color: 0x00ff00});
	var box = new THREE.Mesh(boxGeometry, boxMaterial); //La mesh serve a mettere assieme geometria e materiale
	box.position.set(parameters.cx, parameters.cy, parameters.cz);
	group.add(box);	
}

/*
* read any file and launch the callback funcion on the content
*/
function Read( filePath, callback ){
    var client = new XMLHttpRequest();
    client.open( 'GET', filePath );
    client.onreadystatechange = function() {
        if( client.readyState === 4 )
        {
            if( client.status === 200 || client.status == 0 )
            {
                callback( client.responseText );
            }
        }
    }
    client.send();
}


var selectedObject = null;
function onDocumentMouseMove( event ) {
	event.preventDefault();
	if ( selectedObject ) {
		selectedObject.material.color.set( '#69f' );
		selectedObject = null;
	}
	var intersects = getIntersects( event.layerX, event.layerY );
	if ( intersects.length > 0 ) {
		var res = intersects.filter( function ( res ) {
			return res && res.object;
		} )[ 0 ];
		if ( res && res.object ) {
			selectedObject = res.object;
			selectedObject.material.color.set( '#f00' );
		}
	}
}


function getIntersects( x, y ) {
	x = ( x / window.innerWidth ) * 2 - 1;
	y = - ( y / window.innerHeight ) * 2 + 1;
	mouseVector.set( x, y, 0.5 );
	raycaster.setFromCamera( mouseVector, camera );
	return raycaster.intersectObject( group, true );
}