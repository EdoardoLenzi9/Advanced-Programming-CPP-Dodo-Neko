# Advanced CPP Programming - Project

The project is the implementation of a distributed system for the **shop management**; it has:

* UI (probably an html interface), 
* Business logic (a webservice or simply a program that can interact with the UI)
    * With any kind of API (REST, websockets, ...)
    * Some internal layers (middlewares, controllers, services, repos)
* DBMS


Requirements:

* every layer must be a different process in order to prove that the system is totally distributed 
    * isn't required (but hopeful) that the system will run on different machines in the same network 
* multi-thread (must take care of some simultaneous calls)