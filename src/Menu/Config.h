#ifndef CONFIG_H
#define CONFIG_H


class Config {
public:
   /**Default constructor for the configuration.**/
   Config();

   /**
    * Get the maximum walking distance allowed.
    * @return Returns a double with the maximum walking distance.
    */
   double getWalkingDistance() const;

   /**
    * Change the maximum allowed walking distance.
    * @param distance New walking distance.
    */
   void setWalkingDistance(const double& distance);

   /**
    * Check if day travel is on.
    * @return True if the user is traveling by day and false if the user is traveling night time.
    */
   bool isDayTravel() const;

   /**
    * Sets the traveling time zone to night.
    */
   void setNightTime();

   /**
    * Sets the traveling time zone to day.
    */
   void setDayTime();

private:
   double maximum_walking_distance;
   bool daytime;

};


#endif
