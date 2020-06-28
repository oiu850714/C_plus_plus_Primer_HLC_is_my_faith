ZooAnimal *pb = new Panda("ying_yang");
pb->print(); // ok: Panda::print()
pb->cuddle(); // error: not part of the ZooAnimal interface
pb->highlight(); // error: not part of the ZooAnimal interface
delete pb; // ok: Panda::~Panda()