#include "Board.hpp"
#include "Player.hpp"
#include <map>
#include "City.hpp"
#include "Color.hpp"
using namespace std;
namespace pandemic {


void Board::create_board(){
    
    //connected city - blue 
    set<City> SF_cities = {City::Chicago, City::LosAngeles, City::Tokyo, City::Manila}; //sanfra
    set<City> Ch_cities = {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal};//Chicago
    set<City> MO_cities = {City::Chicago, City::Washington, City::NewYork};//motreal
    set<City> NY_cities = {City::Montreal, City::Washington,City::Madrid,City::London};//newyork
    set<City> WA_cities = {City::NewYork, City::Montreal, City::Atlanta, City::Miami};//washington
    set<City> AT_cities = {City::Chicago, City::Miami, City::Washington};//atlanta

    set<City> MA_cities = {City::NewYork, City::London, City::Paris, City::SaoPaulo, City::Algiers};//madrid
    set<City> LO_cities = {City::NewYork, City::Madrid, City::Paris, City::Essen};//london
    set<City> PA_cities = {City::London, City::Madrid, City::Essen, City::Milan, City::Algiers}; //paris
    set<City> MI_cities = {City::Paris, City::Essen, City::Istanbull};//milan
    set<City> ES_cities = {City::London, City::Paris, City::Milan, City::StPetersburg}; //essen
    set<City> ST_cities = {City::Essen, City::Istanbull, City::Moscow};//st.peterburg
    

    //connected city - yellow
    set<City> LA_cities = {City::SanFrancisco, City::Chicago,City::MexicoCity, City::Sydney}; //los angeles
    set<City> MC_cities = {City::LosAngeles, City::Chicago, City::Miami, City::Bogota, City::Lima};//mexico
    set<City> MAIAM_cities = {City::Atlanta, City::Washington, City::MexicoCity,City::Bogota};//miami
    set<City> BOG_cities = {City::Miami, City::MexicoCity,City::Lima,City::BuenosAires,City::SaoPaulo};//bogota
    set<City> LIM_cities = {City::MexicoCity, City::Bogota, City::Santiago};//lima
    set<City> SAN_cities = {City::Lima};//santiago

    set<City> BUEN_cities = {City::Bogota, City::SaoPaulo};//BuenosAires
    set<City> SAO_cities = {City::Bogota, City::BuenosAires, City::Madrid, City::Lagos};//sao paulo
    set<City> LAG_cities = {City::SaoPaulo, City::Kinshasa, City::Khartoum}; //lagos
    set<City> KIN_cities = {City::Lagos, City::Johannesburg, City::Khartoum};//Kinshasa
    set<City> KHA_cities = {City::Lagos, City::Kinshasa, City::Johannesburg, City::Cairo}; //Khartoum
    set<City> JOH_cities = {City::Kinshasa, City::Khartoum};//Johannesburg


    //connected city - black
    set<City> ALG_cities = {City::Madrid, City::Paris,City::Istanbull, City::Cairo}; //algiers
    set<City> INS_cities = {City::Milan, City::StPetersburg, City::Moscow, City::Algiers, City::Cairo,City::Baghdad};//instanbul
    set<City> CIA_cities = {City::Istanbull, City::Algiers, City::Baghdad,City::Riyadh, City::Khartoum};//ciaro
    set<City> BAGD_cities = {City::Istanbull, City::Cairo,City::Riyadh,City::Karachi,City::Tehran};//bagdad
    set<City> TEH_cities = {City::Moscow, City::Baghdad, City::Karachi, City::Delhi};//teheran
    set<City> RIY_cities = {City::Cairo, City::Baghdad,City::Karachi};//Riyadh

    set<City> KARA_cities = {City::Tehran, City::Delhi, City::Baghdad, City::Riyadh, City::Mumbai};//karachi
    set<City> DEL_cities = {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata};//delhi
    set<City> MUM_cities = {City::Karachi, City::Delhi, City::Chennai}; //mumbai
    set<City> CHEN_cities = {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok,City::Jakarta};//Chennai
    set<City> KOL_cities = {City::Delhi, City::Chennai, City::Bangkok, City::HongKong}; //kolkata
    set<City> MOS_cities = {City::StPetersburg, City::Istanbull, City::Tehran};//moscow

    //connected city - red
    set<City> BEI_cities = {City::Shanghai, City::Seoul}; //beijing
    set<City> SHANG_cities = {City::Beijing, City::Seoul, City::Tokyo, City::HongKong, City::Taipei};//shanghai
    set<City> SEO_cities = {City::Beijing, City::Shanghai, City::Tokyo};//seol
    set<City> OSAK_cities = {City::Tokyo, City::Taipei};//osaka
    set<City> TAIP_cities = {City::Osaka, City::Shanghai, City::HongKong, City::Manila};//taipei
    set<City> HK_cities = {City::Shanghai, City::Taipei,City::Bangkok,City::Manila, City::HoChiMinhCity, City::Kolkata};//hongkong

    set<City> HOCH_cities = {City::Bangkok, City::HongKong, City::Jakarta, City::Manila};//ho chi 
    set<City> JAK_cities = {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};//jakarta
    set<City> BANG_cities = {City::Chennai, City::Kolkata, City::HongKong, City::HoChiMinhCity, City::Jakarta}; //bangkok
    set<City> MANI_cities = {City::Taipei, City::HoChiMinhCity, City::Sydney, City::HongKong, City::SanFrancisco};//manila
    set<City> SYD_cities = {City::Manila, City::Jakarta, City::LosAngeles}; //sydney
    set<City> TOKY_cities = {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};//tokyo


    //blue
    cities_map[City::SanFrancisco] = Square{City::SanFrancisco, Color::Blue, 0, SF_cities};
    cities_map[City::Chicago] = Square{City::Chicago, Color::Blue, 0, Ch_cities};
    cities_map[City::Montreal] = Square{City::Montreal, Color::Blue, 0, MO_cities};
    cities_map[City::NewYork] = Square{City::NewYork, Color::Blue, 0, NY_cities};
    cities_map[City::Washington] = Square{City::Washington, Color::Blue, 0, WA_cities};
    cities_map[City::Atlanta] = Square{City::Atlanta, Color::Blue, 0, AT_cities};
    cities_map[City::Madrid] = Square{City::Madrid, Color::Blue, 0, MA_cities};
    cities_map[City::London] = Square{City::London, Color::Blue, 0, LO_cities};
    cities_map[City::Paris] = Square{City::Paris, Color::Blue, 0, PA_cities};
    cities_map[City::Essen] = Square{City::Essen, Color::Blue, 0, ES_cities};
    cities_map[City::Milan] = Square{City::Milan, Color::Blue, 0, MI_cities};
    cities_map[City::StPetersburg] = Square{City::StPetersburg, Color::Blue, 0, ST_cities};



    //yellow
    cities_map[City::LosAngeles] = Square{City::LosAngeles, Color::Yellow, 0, LA_cities};
    cities_map[City::Miami] = Square{City::Miami, Color::Yellow, 0, MAIAM_cities};
    cities_map[City::MexicoCity] = Square{City::MexicoCity, Color::Yellow, 0, MC_cities};
    cities_map[City::Bogota] = Square{City::Bogota, Color::Yellow, 0, BOG_cities};
    cities_map[City::Lima] = Square{City::Lima, Color::Yellow, 0, LIM_cities};
    cities_map[City::Santiago] = Square{City::Santiago, Color::Yellow, 0, SAN_cities};
    cities_map[City::SaoPaulo] = Square{City::SaoPaulo, Color::Yellow, 0, SAO_cities};
    cities_map[City::BuenosAires] = Square{City::BuenosAires, Color::Yellow, 0, BUEN_cities};
    cities_map[City::Lagos] = Square{City::Lagos, Color::Yellow, 0, LAG_cities};
    cities_map[City::Kinshasa] = Square{City::Kinshasa, Color::Yellow, 0, KIN_cities};
    cities_map[City::Johannesburg] = Square{City::Johannesburg, Color::Yellow, 0, JOH_cities};
    cities_map[City::Khartoum] = Square{City::Khartoum, Color::Yellow, 0, KHA_cities} ;


    //black
    cities_map[City::Istanbull] = Square{City::Istanbull, Color::Black, 0, INS_cities};
    cities_map[City::Algiers] = Square{City::Algiers, Color::Black, 0, INS_cities};
    cities_map[City::Moscow] = Square{City::Moscow, Color::Black, 0, MOS_cities};
    cities_map[City::Tehran] = Square{City::Tehran, Color::Black, 0, TEH_cities};
    cities_map[City::Baghdad] = Square{City::Baghdad, Color::Black, 0, BAGD_cities};
    cities_map[City::Cairo] = Square{City::Cairo, Color::Black, 0, CIA_cities};
    cities_map[City::Riyadh] = Square{City::Riyadh, Color::Black, 0, RIY_cities};
    cities_map[City::Karachi] = Square{City::Karachi, Color::Black, 0, KARA_cities};
    cities_map[City::Delhi] = Square{City::Delhi, Color::Black, 0, DEL_cities};
    cities_map[City::Kolkata] = Square{City::Kolkata, Color::Black, 0, KOL_cities};
    cities_map[City::Mumbai] = Square{City::Mumbai, Color::Black, 0, MUM_cities};
    cities_map[City::Chennai] = Square{City::Chennai, Color::Black, 0, CHEN_cities};
    

    //red
    cities_map[City::Jakarta] = Square{City::Jakarta, Color::Red, 0, JAK_cities};

    cities_map[City::Sydney] = Square{City::Sydney, Color::Red, 0, SYD_cities};
    cities_map[City::Manila] = Square{City::Manila, Color::Red, 0, MANI_cities};
    cities_map[City::HoChiMinhCity] = Square{City::HoChiMinhCity, Color::Red, 0, HOCH_cities};
    cities_map[City::Bangkok] = Square{City::Bangkok, Color::Red, 0, BANG_cities};
    cities_map[City::HongKong] = Square{City::HongKong, Color::Red, 0, HK_cities};
    cities_map[City::Taipei] = Square{City::Taipei, Color::Red, 0, TAIP_cities};
    cities_map[City::Osaka] = Square{City::Osaka, Color::Red, 0, OSAK_cities};
    cities_map[City::Shanghai] = Square{City::Shanghai, Color::Red, 0, SHANG_cities};
    cities_map[City::Tokyo] = Square{City::Tokyo, Color::Red, 0, TOKY_cities};
    cities_map[City::Seoul] = Square{City::Seoul, Color::Red, 0, SEO_cities};
    cities_map[City::Beijing] = Square{City::Beijing, Color::Red, 0, BEI_cities};

    _is_cure_found[Color::Blue] = false;
    _is_cure_found[Color::Yellow] = false;
    _is_cure_found[Color::Black] = false;
    _is_cure_found[Color::Red] = false;

}

bool Board::is_clean() {

   for (map<City,Square>::iterator it = cities_map.begin(); it != cities_map.end(); ++it){

        if (it->second._number_of_dice != 0)
        {
            return false;
        }
        
   }
   return true;
    
}
    
ostream& operator<< (ostream& output,const Board& b){

    return (output << b.cities_map.size()  << " " );
}

void Board::remove_cures(){
    _is_cure_found[Color::Blue] = false;
    _is_cure_found[Color::Yellow] = false;
    _is_cure_found[Color::Black] = false;
    _is_cure_found[Color::Red] = false;
}

void Board::remove_stations(){
    for (map <City, Square>::iterator it=cities_map.begin(); it!=cities_map.end(); ++it)
        it->second._is_station=false;
}
Square::~Square(){

}
Board::~Board(){

}

};