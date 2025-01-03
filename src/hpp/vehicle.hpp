# pragma once



#include "serializer.hpp"
#include <cstdint>



namespace VEHICLE {
namespace S = SERIALIZER;



struct Vehicle {
   virtual ~Vehicle() = default;
   virtual void serialize(S::Serializer& serializer) const = 0;

   struct size_vehicle {
      std::uint32_t length {};
      std::uint32_t width  {};
      std::uint32_t height {};
   };

   size_vehicle  size_vehicle           {};
	std::string   name_vehicle           {};
	std::uint32_t mass_vehicle           {};
	std::uint32_t engine_power           {};
	std::uint32_t passenger_capacity     {};
	std::string   country_of_manufacture {};
};



struct Passenger_Car : Vehicle {
   Passenger_Car (
      const std::string&  name_vehicle,
            std::uint32_t mass_vehicle,
            std::uint32_t engine_power,
            std::uint32_t passenger_capacity,
      const std::string&  country_of_manufacture,
            std::uint32_t length,
            std::uint32_t width,
            std::uint32_t height,
            std::uint8_t  transmission,
            std::uint8_t  drive,
            std::uint16_t engine_displacement_cc,
            std::uint16_t fuel_tank_capacity_l,
            std::uint8_t  fuel_consumption_l_per_100km,
            std::uint8_t  number_of_wheels,
            std::uint8_t  number_of_doors,
            std::uint16_t engine_power_hp,
            std::uint16_t max_speed_kph,
            std::uint16_t cargo_capacity_l,
      const std::string&  color
   ) : transmission                 ( static_cast <transmission_type> (transmission) ),
       drive                        ( static_cast <drive_type>        (drive)        ),
       engine_displacement_cc       ( engine_displacement_cc                         ),
       fuel_tank_capacity_l         ( fuel_tank_capacity_l                           ),
       fuel_consumption_l_per_100km ( fuel_consumption_l_per_100km                   ),
       number_of_wheels             ( number_of_wheels                               ),
       number_of_doors              ( number_of_doors                                ),
       engine_power_hp              ( engine_power_hp                                ),
       max_speed_kph                ( max_speed_kph                                  ),
       cargo_capacity_l             ( cargo_capacity_l                               ),
       color                        ( color                                          )
   {
      this->name_vehicle           = name_vehicle;
      this->mass_vehicle           = mass_vehicle;
      this->engine_power           = engine_power;
      this->passenger_capacity     = passenger_capacity;
      this->country_of_manufacture = country_of_manufacture;
      this->size_vehicle.length    = length;
      this->size_vehicle.width     = width;
      this->size_vehicle.height    = height;
   }

   enum car_class {
      a_segment,
      b_segment,
      c_segment,
      d_segment,
      e_segment,
      f_segment,
      sports_car,
      suv,
      mpv,
      pickup_truck
   };

   enum fuel_type {
      gasoline,
      diesel,
      cng,
      lpg,
      electricity,
      hybrid,
      hydrogen,
      biofuel,
      synthetic_fuel
   };

   enum transmission_type {
      manual,
      automatic,
      cvt,
      semi_automatic
   };

   enum drive_type {
      front_wheel_drive,
      rear_wheel_drive,
      all_wheel_drive,
      four_wheel_drive
   };

   transmission_type transmission {};
   drive_type drive {};

   std::uint16_t engine_displacement_cc       {};
   std::uint16_t fuel_tank_capacity_l         {};
   std::uint8_t  fuel_consumption_l_per_100km {};
   std::uint8_t  number_of_wheels             {};
   std::uint8_t  number_of_doors              {};
   std::uint16_t engine_power_hp              {};
   std::uint16_t max_speed_kph                {};
   std::uint16_t cargo_capacity_l             {};
   std::string   color                        {};

   void serialize(S::Serializer& serializer) const override;
};



struct Plane : public Vehicle {
   Plane (
      const std::string&  name_vehicle,
            std::uint32_t mass_vehicle,
            std::uint32_t engine_power,
            std::uint32_t passenger_capacity,
      const std::string&  country_of_manufacture,
            std::uint32_t length,
            std::uint32_t width,
            std::uint32_t height,
            std::uint8_t  class_type_,
            std::uint8_t  fuel_type_plane_,
            std::uint32_t max_range_km,
            std::uint32_t max_altitude_m,
            std::uint8_t  number_of_engines,
            std::uint32_t cruise_speed_kph
   ) : class_type_plane  ( static_cast <class_type> (class_type_)      ),
       fuel_type_plane   ( static_cast <fuel_type>  (fuel_type_plane_) ),
       max_range_km      ( max_range_km                                ),
       max_altitude_m    ( max_altitude_m                              ),
       number_of_engines ( number_of_engines                           ),
       cruise_speed_kph  ( cruise_speed_kph                            )
   {
      this->name_vehicle           = name_vehicle;
      this->mass_vehicle           = mass_vehicle;
      this->engine_power           = engine_power;
      this->passenger_capacity     = passenger_capacity;
      this->country_of_manufacture = country_of_manufacture;
      this->size_vehicle.length    = length;
      this->size_vehicle.width     = width;
      this->size_vehicle.height    = height;
   }

   enum class_type {
      single_engine,
      twin_engine,
      jet,
      turboprop,
      helicopter
   };

   enum fuel_type {
      avgas,
      jet_fuel,
      diesel,
      electric,
      hybrid,
      hydrogen
   };

   class_type    class_type_plane  {};
   fuel_type     fuel_type_plane   {};
   std::uint32_t max_range_km      {};
   std::uint32_t max_altitude_m    {};
   std::uint8_t  number_of_engines {};
   std::uint32_t cruise_speed_kph  {};

   void serialize(S::Serializer& serializer) const override;
};



struct Ship : Vehicle {
   Ship (
      const std::string&  name_vehicle,
            std::uint32_t mass_vehicle,
            std::uint32_t engine_power,
            std::uint32_t passenger_capacity,
      const std::string&  country_of_manufacture,
            std::uint32_t length,
            std::uint32_t width,
            std::uint32_t height,

            std::uint8_t  ship_type_,
            std::uint8_t  engine_type_,
            std::uint8_t  number_of_decks,
            std::uint16_t max_speed_knots,
            std::uint32_t cargo_capacity_tons
   ) : ship_type__         ( static_cast <ship_type>    (ship_type_)   ),
       engine_type__       ( static_cast <engine_type>  (engine_type_) ),
       number_of_decks     ( number_of_decks                           ),
       max_speed_knots     ( max_speed_knots                           ),
       cargo_capacity_tons ( cargo_capacity_tons                       )
   {
      this->name_vehicle           = name_vehicle;
      this->mass_vehicle           = mass_vehicle;
      this->engine_power           = engine_power;
      this->passenger_capacity     = passenger_capacity;
      this->country_of_manufacture = country_of_manufacture;
      this->size_vehicle.length    = length;
      this->size_vehicle.width     = width;
      this->size_vehicle.height    = height;
   }

   enum ship_type {
      cargo_ship,
      passenger_ship,
      tanker,
      ferry,
      yacht,
      cruise_ship
   };

   enum engine_type {
      diesel_engine,
      steam_engine,
      electric_engine,
      nuclear_engine,
      sail
   };

   ship_type     ship_type__         {};
   engine_type   engine_type__       {};
   std::uint8_t  number_of_decks     {};
   std::uint16_t max_speed_knots     {};
   std::uint32_t cargo_capacity_tons {};

   void serialize(S::Serializer& serializer) const override;
};



};