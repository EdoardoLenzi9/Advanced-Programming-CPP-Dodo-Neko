#ifndef ROUTER_HXX
#define ROUTER_HXX

#include "Route.hxx"


class Router { 
    
    public:
        Router( vector<Route> routes ) : routes(routes) {};
        void start();

    private:
        vector<Route> routes;
};


#endif