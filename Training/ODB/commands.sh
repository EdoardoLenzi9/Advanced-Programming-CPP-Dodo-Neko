odb -d sqlite --generate-query --generate-schema dodo.hxx
odb -d sqlite -s -q person.hxx

g++ -o driver driver.cxx dodo-odb.cxx -lodb-sqlite -lodb

g++ -o driver driver.cxx Repositories/BookRepository-odb.cxx -lodb-sqlite -lodb
g++ -o driver driver.cxx Repositories/*-odb.cxx -lodb-sqlite -lodb