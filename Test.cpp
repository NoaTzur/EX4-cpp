#include <iostream>
#include <stdexcept>
#include <string>
#include "doctest.h"
#include <map>
#include <vector>
#include "OperationsExpert.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"


using namespace pandemic;
TEST_CASE("Player"){
    Board b;
    Player p{b,City::Bogota};
    CHECK_THROWS(p.fly_shuttle(City::Istanbull)); // not a esearch station
    CHECK_THROWS(p.drive(City::Madrid)); //not connected
    p.take_card(City::Madrid); 
    CHECK_NOTHROW(p.fly_direct(City::Madrid));
    
    
    p.take_card(City::Madrid);
    CHECK_NOTHROW(p.fly_charter(City::Karachi));
    CHECK_THROWS(p.fly_charter(City::Karachi));

    p.take_card(City::Karachi);
    CHECK_NOTHROW(p.build()); //in Karachi
    p.take_card(City::Delhi).
    take_card(City::Karachi).
    take_card(City::Kolkata).
    take_card(City::Tehran).
    take_card(City::Istanbull);

    CHECK_THROWS(p.discover_cure(Color::Red));
    CHECK_NOTHROW(p.discover_cure(Color::Black));
}


TEST_CASE("Dispatcher"){
    Board b;
    
    Dispatcher d{b, City::Chicago};
    d.take_card(City::Chicago);

    CHECK_THROWS(d.fly_direct(City::HongKong));
    d.build();
    CHECK_NOTHROW(d.fly_direct(City::HongKong));
}

TEST_CASE("Scientist"){
    Board b;

    Scientist s{b,City::Essen,1};
    s.take_card(City::Essen);
    s.build();
    s.take_card(City::Madrid);
    CHECK_NOTHROW(s.discover_cure(Color::Blue));

}

TEST_CASE("Researcher"){
    Board b;

    Researcher j{b, City::Madrid};
    CHECK_THROWS(j.discover_cure(Color::Blue));
    j.take_card(City::StPetersburg).
    take_card(City::Milan).
    take_card(City::NewYork).
    take_card(City::Paris).
    take_card(City::Atlanta);

    CHECK_NOTHROW(j.discover_cure(Color::Blue));
    
    
}

TEST_CASE("Medic"){

    Board b;
    CHECK_NOTHROW(b[City::Atlanta] = 5); // checks operator[]

    Medic m{b,City::Atlanta};
    m.take_card(City::Atlanta).take_card(City::NewYork);

    CHECK_EQ(b.cities_map[City::Atlanta]._number_of_dice, 5);

    m.treat(City::Atlanta);
    CHECK_EQ(b.cities_map[City::Atlanta]._number_of_dice, 0);

}
TEST_CASE("Virologist"){

    Board b;
    Virologist v{b,City::Chicago};
    b[City::Jakarta] = 5;
    CHECK_EQ(b[City::Jakarta], 5);
    v.take_card(City::Jakarta);
    v.treat(City::Jakarta);
    CHECK_EQ(b[City::Jakarta], 4);
    
}
TEST_CASE("GeneSplicer"){

    Board b;
    GeneSplicer g{b,City::Algiers};
    g.take_card(City::Algiers);
    CHECK_THROWS(g.discover_cure(Color::Yellow));
    g.build();
    g.take_card(City::LosAngeles).
    take_card(City::Paris).
    take_card(City::Essen).
    take_card(City::SanFrancisco).
    take_card(City::Manila);

    CHECK_NOTHROW(g.discover_cure(Color::Yellow));
    


}