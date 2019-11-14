var scene, camera, renderer, box;

function Init(){
	scene = new THREE.Scene();
	camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
	camera.position.z = 5;
	// 75 angolo di apertura di una camera 
	// rapporto di aspect ratio dell'immagine, rapporto larghezza/altezza 
	// distanza minima di un oggetto dalla camera per poter essere visto
	// distanza massima

	// Per creare un oggetto ho bisogno di geometria, materiale e mesh
	boxGeometry = new THREE.CubeGeometry(1,1,1); // larghezza, altezza, profondita'
	boxMaterial = new THREE.MeshBasicMaterial({color: 0x00ff00});
	box = new THREE.Mesh(boxGeometry, boxMaterial); //La mesh serve a mettere assieme geometria e materiale
	scene.add(box);

	renderer = new THREE.WebGLRenderer();
	renderer.setSize(window.innerWidth, window.innerHeight);
	document.body.appendChild(renderer.domElement)
}

function Render(){
	// Inserisco la chiamata ricorsiva nel loop stesso del web browser che comunque fa un render del codice
	requestAnimationFrame(Render); // Render();
	renderer.render(scene, camera);
}

Init();
Render();