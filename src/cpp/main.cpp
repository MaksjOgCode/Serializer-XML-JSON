#include "vehicle.hpp"



void serialize(const VEHICLE::Vehicle& vehicle, SERIALIZER::Serializer& serializer_object) {
   vehicle.serialize(serializer_object);
}



void init_vector_of_vehicles(std::vector < std::unique_ptr <VEHICLE::Vehicle> >& vehicles);



int main( int argc, char* argv[] ) {
   std::vector < std::unique_ptr <VEHICLE::Vehicle> > vehicles { };
   init_vector_of_vehicles(vehicles);

   if (argc > 1) {
       std::string_view format = argv[1];
       
       if (format == "xml") {
          SERIALIZER::XML_Serializer  xml_serializer {};
       
          xml_serializer.add_block("Vehicles");
          for (const auto& vehicle : vehicles)
             serialize(*vehicle, xml_serializer);
       
          xml_serializer.build();
       
       } else if (format == "json") {
          SERIALIZER::JSON_Serializer json_serializer {};
       
          json_serializer.add_block("Vehicles");
          for (const auto& vehicle : vehicles)
              serialize(*vehicle, json_serializer);
       
          json_serializer.build();
       }

       return 0;
   }

   SERIALIZER::XML_Serializer  xml_serializer  {};
   SERIALIZER::JSON_Serializer json_serializer {};

   xml_serializer.add_block("Vehicles");
   json_serializer.add_block("Vehicles");
   for (const auto& vehicle : vehicles)
   {
      serialize(*vehicle, xml_serializer);
      serialize(*vehicle, json_serializer);
   }

   json_serializer.build();
   xml_serializer.build();

	return 0;
}



void init_vector_of_vehicles(std::vector < std::unique_ptr <VEHICLE::Vehicle> >& vehicles) {
   /* Add Car: */
   vehicles.push_back( std::make_unique <VEHICLE::Passenger_Car> (
      "BMW 530i",
      1605,
      248,
      5,
      "Germany",
      4935,
      1868,
      1469,
      VEHICLE::Passenger_Car::automatic,
      VEHICLE::Passenger_Car::rear_wheel_drive,
      1998, 68,
      6,
      4,
      4,
      248,
      250,
      530,
      "Blue"
   ));

   /* Add Airplane: */
   vehicles.push_back(std::make_unique <VEHICLE::Plane>(
      "Boeing 747",
      183500,
      250000,
      524,
      "USA",
      7066,
      6840,
      1941,
      VEHICLE::Plane::jet,
      VEHICLE::Plane::jet_fuel,
      13450,
      13100,
      4,
      907
   ));

   /* Add ship: */
   vehicles.push_back( std::make_unique <VEHICLE::Ship> (
      "QUEEN MARY 2",
      76000,
      117000,
      2691,
      "France",
      345,
      41,
      72,
      VEHICLE::Ship::cruise_ship,
      VEHICLE::Ship::diesel_engine,
      13,
      30,
      0
   ));
}