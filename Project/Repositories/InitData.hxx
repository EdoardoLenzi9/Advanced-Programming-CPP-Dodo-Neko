using namespace std;

#include "Repository.hxx"
#include "Authorization.hxx"
#include "FeatureType.hxx"
#include "Role.hxx"
#include "Room.hxx"
#include "RoomFeature.hxx"
#include "User.hxx"


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

            userRepo->create(new User("admin1", "pw1", 3));

            userRepo->create(new User("staff1", "pw1", 2));
            userRepo->create(new User("staff2", "pw2", 2));
            
            userRepo->create(new User("user1", "pw1", 1));
            userRepo->create(new User("user2", "pw2", 1));
            userRepo->create(new User("user3", "pw3", 1));

            /* Init rooms */

            roomRepo->create(new Room(1));
            roomRepo->create(new Room(1));
            roomRepo->create(new Room(1));
            roomRepo->create(new Room(1));

            roomRepo->create(new Room(2));
            roomRepo->create(new Room(2));
            roomRepo->create(new Room(2));
            roomRepo->create(new Room(2));

            roomRepo->create(new Room(3));
            roomRepo->create(new Room(3));

            roomRepo->create(new Room(4));
            roomRepo->create(new Room(4));
            
            /* Init features */

            featureRepo->create(new FeatureType("private parking", 10));
            featureRepo->create(new FeatureType("spa", 30));
            featureRepo->create(new FeatureType("massage", 10));
            featureRepo->create(new FeatureType("swim pool", 10));
            featureRepo->create(new FeatureType("sauna", 15));
            featureRepo->create(new FeatureType("dinner", 20));
            featureRepo->create(new FeatureType("breakfast", 5));
            featureRepo->create(new FeatureType("gym", 0));
            featureRepo->create(new FeatureType("air-conditioning", 3));
        }
};