using namespace std;

#include "Repository.hxx"
#include "Authorization.hxx"
#include "FeatureType.hxx"
#include "Role.hxx"
#include "Room.hxx"
#include "RoomFeature.hxx"
#include "User.hxx"
#include "sha256.hxx"


class InitData{
    private:
        Repository<Authorization>* authRepo;
        Repository<FeatureType>* featureRepo;
        Repository<Role>* roleRepo;
        Repository<Room>* roomRepo;
        Repository<RoomFeature>* RoomFeatureRepo;
        Repository<User>* userRepo;     

    public:
        InitData(){
            roleRepo = new Repository<Role>();
            userRepo = new Repository<User>();
            roomRepo = new Repository<Room>();
            authRepo = new Repository<Authorization>();
            featureRepo = new Repository<FeatureType>();
            RoomFeatureRepo = new Repository<RoomFeature>();

            /* Init roles */

            roleRepo->create(new Role("Customer"));
            roleRepo->create(new Role("Staff"));
            roleRepo->create(new Role("Administrator"));

            /* Init users */

            userRepo->create(new User("admin1", sha256("pw1"), 3));

            userRepo->create(new User("staff1", sha256("pw1"), 2));
            userRepo->create(new User("staff2", sha256("pw2"), 2));
            
            userRepo->create(new User("user1", sha256("pw1"), 1));
            userRepo->create(new User("user2", sha256("pw2"), 1));
            userRepo->create(new User("user3", sha256("pw3"), 1));

            /* Init rooms */

            roomRepo->create(new Room(101));
            roomRepo->create(new Room(102));
            roomRepo->create(new Room(103));
            roomRepo->create(new Room(104));

            roomRepo->create(new Room(201));
            roomRepo->create(new Room(202));
            roomRepo->create(new Room(203));
            roomRepo->create(new Room(237));

            roomRepo->create(new Room(301));
            roomRepo->create(new Room(302));

            roomRepo->create(new Room(401));
            roomRepo->create(new Room(402));
            
            /* Init features */

            featureRepo->create(new FeatureType("Baseprice", 25));          /*1*/
            featureRepo->create(new FeatureType("Beds", 10));               /*2*/
            featureRepo->create(new FeatureType("Swimming pool", 10));      /*3*/
            featureRepo->create(new FeatureType("Gym", 20));                /*4*/
            featureRepo->create(new FeatureType("Air-conditioning", 3));    /*5*/
            featureRepo->create(new FeatureType("Sauna", 20));              /*6*/
            featureRepo->create(new FeatureType("Private parking", 10));    /*7*/
            featureRepo->create(new FeatureType("Mountain View", 10000));   /*8*/

            /* Room features */

            /* First floor*/
            RoomFeatureRepo->create(new RoomFeature(1, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(1, 2, 1)); // beds
            RoomFeatureRepo->create(new RoomFeature(1, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(1, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(2, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(2, 2, 2)); // beds
            RoomFeatureRepo->create(new RoomFeature(2, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(2, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(3, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(3, 2, 1)); // beds
            RoomFeatureRepo->create(new RoomFeature(3, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(4, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(4, 2, 2)); // beds
            RoomFeatureRepo->create(new RoomFeature(4, 7, 1)); // private parking

            /* Second floor*/
            RoomFeatureRepo->create(new RoomFeature(5, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(5, 2, 1)); // beds
            RoomFeatureRepo->create(new RoomFeature(5, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(5, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(5, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(6, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(6, 2, 2)); // beds
            RoomFeatureRepo->create(new RoomFeature(6, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(6, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(6, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(7, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(7, 2, 1)); // beds
            RoomFeatureRepo->create(new RoomFeature(7, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(7, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(7, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(8, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(8, 2, 2)); // beds
            RoomFeatureRepo->create(new RoomFeature(8, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(8, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(8, 7, 1)); // private parking

            /* Third floor*/
            RoomFeatureRepo->create(new RoomFeature(9, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(9, 2, 3)); // beds
            RoomFeatureRepo->create(new RoomFeature(9, 3, 1)); // pool
            RoomFeatureRepo->create(new RoomFeature(9, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(9, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(9, 6, 1)); // sauna
            RoomFeatureRepo->create(new RoomFeature(9, 7, 1)); // private parking

            RoomFeatureRepo->create(new RoomFeature(10, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(10, 2, 4)); // beds
            RoomFeatureRepo->create(new RoomFeature(10, 3, 1)); // pool
            RoomFeatureRepo->create(new RoomFeature(10, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(10, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(10, 6, 1)); // sauna
            RoomFeatureRepo->create(new RoomFeature(10, 7, 1)); // private parking

            /* Last floor*/            
            RoomFeatureRepo->create(new RoomFeature(11, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(11, 2, 2)); // beds
            RoomFeatureRepo->create(new RoomFeature(11, 3, 1)); // pool
            RoomFeatureRepo->create(new RoomFeature(11, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(11, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(11, 6, 1)); // sauna
            RoomFeatureRepo->create(new RoomFeature(11, 7, 1)); // private parking
            RoomFeatureRepo->create(new RoomFeature(11, 8, 1)); // mountain view

            RoomFeatureRepo->create(new RoomFeature(12, 1, 1)); // base price
            RoomFeatureRepo->create(new RoomFeature(12, 2, 2)); // beds
            RoomFeatureRepo->create(new RoomFeature(12, 3, 1)); // pool
            RoomFeatureRepo->create(new RoomFeature(12, 4, 1)); // gym
            RoomFeatureRepo->create(new RoomFeature(12, 5, 1)); // air-conditioning
            RoomFeatureRepo->create(new RoomFeature(12, 6, 1)); // sauna
            RoomFeatureRepo->create(new RoomFeature(12, 7, 1)); // private parking
            RoomFeatureRepo->create(new RoomFeature(12, 8, 1)); // mountain view
        }
};