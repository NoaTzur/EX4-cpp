#pragma once

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {

  class Medic : public Player
  {
  private:

  public:
    

    Player& drive(const City& c){
      
      Player::drive(c);
      Color temp = _board.cities_map[c]._color;
      if (_board._is_cure_found[temp])
      {
        Medic::treat(c);
      }
      return *this;

    }
    Player& fly_direct(const City &c) {
      
      Player::fly_direct(c);
      Color temp = _board.cities_map[c]._color;
      if (_board._is_cure_found[temp])
      {
        Medic::treat(c);
      }
      return *this;
    }
    Player& fly_charter(const City &c) {
      
      Player::fly_charter(c);
      Color temp = _board.cities_map[c]._color;
      if (_board._is_cure_found[temp])
      {
        Medic::treat(c);
      }
      return *this;

    }
    Player& fly_shuttle(const City &c){
      
      Player::fly_shuttle(c);
      Color temp = _board.cities_map[c]._color;
      if (_board._is_cure_found[temp])
      {
        Medic::treat(c);
      }
      return *this;
    }
    Player& treat(const City &c){//if there is a cure for the specific color, call treat in every city he goto

    if (_board.cities_map[_city]._number_of_dice > 0)
    {   
      _board.cities_map[_city]._number_of_dice = 0;
    }
    else{
         throw std::invalid_argument("number of dice is already 0");
    }


    return *this;
    } 

    std::string role(){
            return "Medic";
        }

    Medic(Board &board, City city):Player(board,city){}
    ~Medic(){}
  };

};