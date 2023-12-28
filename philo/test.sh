#!/bin/bash

# 1. number_of_philosophers
# 2. time_to_die
# 3. time_to_eat
# 4. time_to_sleep
# 5. number_of_times_each_philosopher_must_eat

ARGS1="./philo \
2147483647 \
21479p83647 \
2147483647 \
2147483647 \
tur&"

ARGS2="./philo \
200 \
800 \
100 \
100 \
"

# echo ${ARGS1}
# $ARGS1
echo ${ARGS2}
$ARGS2