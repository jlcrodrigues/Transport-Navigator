#ifndef CONFIG_H
#define CONFIG_H


class Config {
public:
   /**Default constructor for the configuration.**/
   Config();

   double getWalkingDistance() const;

   void setWalkingDistance(const double& distance);

private:
   double maximum_walking_distance;

};


#endif
