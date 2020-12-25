#include "task_test.h"
#include <iostream>
void testFunction()
{
	Task task = Task("test",123,567);
	std::cout << task;
}
/*
void TaskTest::setUp() {
		this->objet_a_tester = new Task();
}

void TaskTest::tearDown() {
		delete this->objet_a_tester;
}

void TaskTest::test_1_task() {
	int id = 25001;
	this->objet_a_tester->ajouterClient(new Client(id, "nom", "prenom", 60, "H1C", {0,0,0,0,0,0,0,0,0}));
	Facture une_facture;
	une_facture.ajouterItem(1000);
	float rabais = this->objet_a_tester->getRabais(une_facture, id);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.15, rabais, FLT_EPSILON);
}

void TaskTest::test_2_task() {
	int id = 25001;
	this->objet_a_tester->ajouterClient(new Client(id, "nom", "prenom", 60, "H1C", {0,0,0,0,0,0,0,0,0}));
	Facture une_facture;
	une_facture.ajouterItem(1000);
	float rabais = this->objet_a_tester->getRabais(une_facture, id);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.15, rabais, FLT_EPSILON);
}
*/