#include "vehicle.hpp"



namespace V = VEHICLE;



void V::Passenger_Car::serialize(S::Serializer& serializer) const {
   serializer.add_block ( "Passenger Car" );
   serializer.add_field ( "Name Vehicle",                 this->name_vehicle                                 );
   serializer.add_field ( "Mass Vehicle",                 std::to_string(this->mass_vehicle)                 );
   serializer.add_field ( "Engine Power",                 std::to_string(this->engine_power)                 );
   serializer.add_field ( "Passenger Capacity",           std::to_string(this->passenger_capacity)           );
   serializer.add_field ( "Country of Manufacture",       this->country_of_manufacture                       );
   serializer.add_field ( "Length Vehicle",               std::to_string(this->size_vehicle.length)          );
   serializer.add_field ( "Width Vehicle",                std::to_string(this->size_vehicle.width)           );
   serializer.add_field ( "Height Vehicle",               std::to_string(this->size_vehicle.height)          );
   serializer.add_field ( "Transmission Type",            std::to_string(this->transmission)                 );
   serializer.add_field ( "Drive Type",                   std::to_string(this->drive)                        );
   serializer.add_field ( "Engine Displacement",          std::to_string(this->engine_displacement_cc)       );
   serializer.add_field ( "Fuel Tank Capacity",           std::to_string(this->fuel_tank_capacity_l)         );
   serializer.add_field ( "Fuel Consumption Per 100(KM)", std::to_string(this->fuel_consumption_l_per_100km) );
   serializer.add_field ( "Number of Wheels",             std::to_string(this->number_of_wheels)             );
   serializer.add_field ( "Number of Doors",              std::to_string(this->number_of_doors)              );
   serializer.add_field ( "Engine Power",                 std::to_string(this->engine_power_hp)              );
   serializer.add_field ( "Max Speed",                    std::to_string(this->max_speed_kph)                );
   serializer.add_field ( "Cargo Capacity",               std::to_string(this->cargo_capacity_l)             );
   serializer.add_field ( "Color Car",                    this->color                                        );
}



void  V::Plane::serialize(S::Serializer& serializer) const {
   serializer.add_block ( "Plane" );
   serializer.add_field ( "Name Vehicle",           name_vehicle                        );
   serializer.add_field ( "Mass Vehicle",           std::to_string(mass_vehicle)        );
   serializer.add_field ( "Engine Power",           std::to_string(engine_power)        );
   serializer.add_field ( "Passenger Capacity",     std::to_string(passenger_capacity)  );
   serializer.add_field ( "Country of Manufacture", country_of_manufacture              );
   serializer.add_field ( "Size Vehicle Length",    std::to_string(size_vehicle.length) );
   serializer.add_field ( "Size Vehicle Width",     std::to_string(size_vehicle.width)  );
   serializer.add_field ( "Size Vehicle Height",    std::to_string(size_vehicle.height) );
   serializer.add_field ( "Class Type",             std::to_string(class_type_plane)    );
   serializer.add_field ( "Fuel Type",              std::to_string(fuel_type_plane)     );
   serializer.add_field ( "Number of Engines",      std::to_string(number_of_engines)   );
   serializer.add_field ( "Max Range (KM)",         std::to_string(max_range_km)        );
   serializer.add_field ( "Cruise Speed (KPH)",     std::to_string(cruise_speed_kph)    );
   serializer.add_field ( "Max Altitude (M)",       std::to_string(max_altitude_m)      );
}



void V::Ship::serialize(S::Serializer& serializer) const {
   serializer.add_block ( "Ship" );
   serializer.add_field ( "Name Vehicle",           name_vehicle                        );
   serializer.add_field ( "Mass Vehicle",           std::to_string(mass_vehicle)        );
   serializer.add_field ( "Engine Power",           std::to_string(engine_power)        );
   serializer.add_field ( "Passenger Capacity",     std::to_string(passenger_capacity)  );
   serializer.add_field ( "Country of Manufacture", country_of_manufacture              );
   serializer.add_field ( "Size Vehicle Length",    std::to_string(size_vehicle.length) );
   serializer.add_field ( "Size Vehicle Width",     std::to_string(size_vehicle.width)  );
   serializer.add_field ( "Size Vehicle Height",    std::to_string(size_vehicle.height) );
   serializer.add_field ( "Ship Type",              std::to_string(ship_type__)         );
   serializer.add_field ( "Engine Type",            std::to_string(engine_type__)       );
   serializer.add_field ( "Number of Decks",        std::to_string(number_of_decks)     );
   serializer.add_field ( "Max Speed Knots",        std::to_string(max_speed_knots)     );
   serializer.add_field ( "Cargo Capacity Tons",    std::to_string(cargo_capacity_tons) );
}