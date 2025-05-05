#ifndef CONFIG_H
#define CONFIG_H

// Helpers
#define GET_SECONDS(hour)   hour * 60 * 60 

// Config
#define SANDWICH_EAT_PER_S_PROBABILITY      0.001  // 
#define SANDWICH_PRICE                      1.5     // EUR
#define SANDWICH_FRESH_LENGTH   GET_SECONDS(1)   // Hrs
#define SANDWICH_PROD_TIME      GET_SECONDS(3)     
#define SANDWICH_PROD_COUNT                 10 
#define WORKDAY_LENGTH          GET_SECONDS(12)

#endif
