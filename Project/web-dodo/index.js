/*
* Main view script
*
* author = 'Marco Iuri, Edoardo Lenzi'
* version = '1.0'
* license = 'GPL-3.0'
*/


/*  
* Slicknav script 
*/
$(document).ready(function(){
    $( '#small-nav' ).slicknav({
        'label': 'Iurinzi',
        closeOnClick: true
    });
});


/*  
* Parallax script 
* see: https://www.marchettidesign.net/demo/parallax-design-responsive
*/
$(document).ready(function(){
    $( '#adb' ).modal();
    $( '.toast' ).toast( 'show' );
    //$('.toast').toast({delay:100, animation:false});
    $window = $( window );            
    $( '.full-panel' ).each( function() {
        var $scroll = $( this );
        $(window).scroll(function() {
            var yPos = -( $window.scrollTop() / 10 );
            // background position
            var coords = '50% ' + yPos + 'px';
            // move the background
            $scroll.css({ backgroundPosition: coords });
        }); 
    });  
});


/*
* Fix navbar once scroll
*/
window.onscroll = function() { stickyNavbar(); };

var header = document.getElementById('large-nav');
var sticky = header.offsetTop;

function stickyNavbar() {
    if ( window.pageYOffset > sticky ) {
        header.classList.add( 'sticky' );
    } else {
        header.classList.remove( 'sticky' );
    }
}