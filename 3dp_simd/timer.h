#ifndef timer_h
#define timer_h
#include <map>
#include <sys/time.h>

namespace exafmm {
  static timeval t;                                             //!< Time value
  static std::map<std::string,timeval> timer;                   //!< Map of timer event name to time value

  //! Start timer for given event
  /*!
    \param event event name
  */ 
  void start(std::string event) {
    gettimeofday(&t, NULL);                                     // Get time of day in seconds and microseconds
    timer[event] = t;                                           // Store in timer
  }

  //! Stop timer for given event
  /*!
    \param event event name
    \return eventTime event time in seconds
  */
  double stop(std::string event) {
    gettimeofday(&t, NULL);                                     // Get time of day in seconds and microseconds
    double eventTime = t.tv_sec - timer[event].tv_sec +         // Calculate event time
                     (t.tv_usec - timer[event].tv_usec) * 1e-6;
    printf("%-20s : %f s\n", event.c_str(), eventTime);         // Print time difference
    return eventTime;
  }
}
#endif
