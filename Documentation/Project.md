# Distributed System for hotel management


## Requirements 

* Inheritance/Encapsulation/Polymorphism/Templates
* Split the code in terms of interfaces (headers) and libraries
* Multi-threading

* Distributed (three-tier)
    * API REST, SOAP, RPC or WebSockets
* Database not directly accessible
* UI


## Milestones


### Milestone 2

* Use-cases for the system
* Actors identification
* System architecture


### Milestone 3

* Initial version with limited functionalities (no multithread)


### Milestone 4 

* Parallel version with multithreading support


### Milestone 5

* System with all the functionalities
* Distributed
* Support for multiprocess communication

---

# Abstract

We are going to create an Hotel management system, the system will be able to manage customers 
with a simple user interface; in particular a customer can see the list of available rooms,
reserve a room, delete a reservation, and manage few other aspects (ie. breakfast, parking, spa, gym, massage rooms, ...).
At the same time the Hotel staff can see the Hotel state, change reservations 
(ie. move a customer from a room to another one) and send communications to the customers.


# Introduction - The problem

Basically the problem forces us to implement a distributed system, 
multi-role (customer and hotel staff), able to take care of concurrent calls (multi-thread),
consistent (every non-idempotent query will be a atomic) with a reasonable complexity 
in terms of entities / actors. 

The system may be fault tolerant, fair and without deadlocks, starvation.


# Analysis


## Functional Requirements


The system main features (high level features) are:

* A customer can see the available rooms in a certain instant
* A customer can reserve a room in a certain instant
    * can reserve also additional services (ie. breakfast, parking, spa, gym, massage rooms, ...) when (s)he has a reserved room
    * can delete a reservation of a room and/or of an additional service
* A customer can send/receive communications from the hotel staff
* An employee (hotel staff) can manage the reservations of both rooms and additional services 
    * delete a reservation
    * change rooms (ie. swap two rooms)
    * delete an additional service
    * send a communication to a customer
* General error management architecture


## Non-Functional Requirements


* Fault tolerant
* Security (avoid sql-injection and MIM attacks)
* Consistent and Fair (wrt concurrent reservations, communications)
* Strong (in terms of work-load, starvation and deadlocks)
* Scalable (well designed in order to be easily scalable, 
    ie. allows to create a P2P network of web services with a load-balancer)


# Project


## Logical Architecture

The logical architecture is composed by the following components:

* 1st tier - DBMS with a stand-alone repository interface that allows to interact with the DB
* 2nd tier - WebServer that exposes a RESTful API and some static files
    * It is subdivided into some layers: 
        * Middleware Layer takes care of some common features (ie. authentication, parameters validation)
        * Controller Layer takes care of the incoming calls (data marshalling/unmarshalling) and calls the business logic routines
        * Service Layer contains the business logic and calls the 1st tier in order to retrieve/push data into the DB
* 3rd tier - UI will be a simple web interface (HTML + CSS + JS) able to call the RESTful API with AJAX calls 

The architecture is a three tier MVC and fulfills the project requirements, moreover it uses some programming patterns like:
* Repository pattern
* CQRS pattern


## Protocols and Algorithms

Following the *divide et impera* philosophy now we are going to split the problem into some subproblems and solve them.


### Consistency and concurrency

The worst scenario possible is when two customers at the same instant reserve the same available room;
we will use a transactions for each query in order to avoid problems on the 1st layer in conjunction with 
a UI polling policy and a semaphore on the Service layer.

Another problem can be the chat between an employee and a customer but we aren't going to syncronize
the clocks (Berkeley algorithm) or use a total order algorithm otherwise the project will become too complicated.
We simply are going to see the conversations from the point of view of the web server and update consistently 
the chats using a polling/long polling policy.


### Security 

The security problems under consideration are:
* SQL-injection (solvable with an ORM)
* MIM attack (solvable using HTTPS)
* DoS attack (we can think about a call log, MAC/IP ban, but the system itself will, 
    for sure be able to manage huge number of calls so we aren't going take this aspect into account)
* Authentication (each API call must be validated)
* Role management (setup a strong visibility criterion in order to respect the roles)


## Physical architecture and deployment

A makefile will take care of the setup/deployment of the project.

We adopt Git for code versioning and a feature oriented branching strategy with a PR foreach merge.
The code required for the simulation is taken directly from the project repository hosted on GitHub.


## Development plan

Following the Agile philosophy we are going to split the the development process in some sprints of few weeks and 
adopt a TDD methodology.


# Implementation

## Assumptions 

## Tools 

We will use `C++` for the implementation of the web service and the repository library 
and web technologies (html, css, js) for the UI implementation. 

### Web Service 

We will create a simple web service starting from this [example](https://github.com/eidheim/Simple-Web-Server),
we will create manually a RESTful API (cause there isn't any valid Web Framework to do it!).  


### Repository library

The repository library follows the CRUD logic and uses odb as ORM,
tries also to separate idempotent queries from non-idempontent commands following the CQRS pattern.

Exposes an interface for the web service interconnection (TODO which kind of interface? fifo, mq, socket, ...).

The DBMS will be a relational SQL DB like SQLITE or an instance of MariaDB 
(it doesn't matter what we choose cause odb will take care of the DB connection 
and we are free to change DBMS at any moment)


### UI

A simple web UI designed with Bootstrap and Vue.js 


# Validation

Some unit tests will take care about the logic validation.


# Conclusions

Those are some ideas, the project is really complicated and C++ isn't the fast tool to achieve 
those goals so we aren't sure that every point will be accomplished also cause we are a small group 
and the exam weight only 2 credits (and require a deep knowledge in some fields 
(OSs, Distributed Systems, Networks, OOP programming)).