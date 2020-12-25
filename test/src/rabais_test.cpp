#include "rabais_test.h"
#include <iostream>
void testFunction()
{
	Task task = Task("test",123,567);
	std::cout << task;
}
/*
void RabaisTest::setUp() {
		this->objet_a_tester = new Rabais();
}

void RabaisTest::tearDown() {
		delete this->objet_a_tester;
}

// Format conceptuel des cas des tests :
// dx = <{facture, client}, {rabaisSupposé}>

// Correspond à d1 = <{(1000), (25001, "nom", "prenom", 60, "H1H", (0, 0, 1900))}, {0.15}>
void RabaisTest::test_rabais_employee() {
	int id = 25001;
	this->objet_a_tester->ajouterClient(new Client(id, "nom", "prenom", 60, "H1C", {0,0,0,0,0,0,0,0,0}));
	Facture une_facture;
	une_facture.ajouterItem(1000);
	float rabais = this->objet_a_tester->getRabais(une_facture, id);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.15, rabais, FLT_EPSILON);
}

// Correspond à d2 = <{(0), (1, "nom", "prenom", 60, "AAA", (date_actuelle))}, {0.10}>
void RabaisTest::test_rabais_age_plus_que_55() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 60, "AAA", *now));
	Facture une_facture;
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.10, rabais, FLT_EPSILON);
}

// Correspond à d3 = <{(0), (1, "nom", "prenom", 1, "H1C", (date_actuelle))}, {0.04}>
void RabaisTest::test_rabais_code_postal_H1C() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "H1C", *now));
	Facture une_facture;
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.04, rabais, FLT_EPSILON);
}

// Correspond à d4 = <{(0), (1, "nom", "prenom", 1, "H3P", (date_actuelle))}, {0.03}>
void RabaisTest::test_rabais_code_postal_H3P() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "H3P", *now));
	Facture une_facture;
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.03, rabais, FLT_EPSILON);
}

// Correspond à d5 = <{(0), (1, "nom", "prenom", 1, "J4O", (date_actuelle))}, {0.02}>
void RabaisTest::test_rabais_code_postal_J4O() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "J4O", *now));
	Facture une_facture;
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.02, rabais, FLT_EPSILON);
}

// Correspond à d6 = <{(0), (1, "nom", "prenom", 1, "AAA", (date_actuelle - 15 ans))}, {0.10}>
void RabaisTest::test_rabais_adhesion_15_ans() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	now->tm_year -= 15;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "AAA", *now));
	Facture une_facture;
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.10, rabais, FLT_EPSILON);
}

// Correspond à d7 = <{(0), (1, "nom", "prenom", 1, "AAA", (date_actuelle - 20 ans))}, {0.10}>
void RabaisTest::test_rabais_adhesion_plus_que_15_ans() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	now->tm_year -= 20;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "AAA", *now));
	Facture une_facture;
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.10, rabais, FLT_EPSILON);
}


// Correspond à d8 = <{(0), (1, "nom", "prenom", 1, "AAA", (date_actuelle))}, {0.0}>
void RabaisTest::test_rabais_aucun_achat() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "AAA", *now));
	Facture une_facture;
	une_facture.ajouterItem(0);
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, rabais, FLT_EPSILON);
}

// Correspond à d9 = <{(720), (1, "nom", "prenom", 1, "AAA", (date_actuelle))}, {0.06}>
void RabaisTest::test_rabais_achat_720_dollars() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "AAA", *now));
	Facture une_facture;
	une_facture.ajouterItem(720);
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.06, rabais, FLT_EPSILON);
}

// Correspond à d10 = <{(1000), (1, "nom", "prenom", 1, "AAA", (date_actuelle))}, {0.06}>
void RabaisTest::test_rabais_achat_plus_que_720_dollars() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	this->objet_a_tester->ajouterClient(new Client(1, "nom", "prenom", 1, "AAA", *now));
	Facture une_facture;
	une_facture.ajouterItem(1000);
	float rabais = this->objet_a_tester->getRabais(une_facture, 1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.06, rabais, FLT_EPSILON);
}*/
