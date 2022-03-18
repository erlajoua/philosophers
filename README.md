## Philosophers (Dining Problem)

### Description :sparkles:
Philosophers is a 42 project, coded in C that deals with the well-known problem of the Philosophers' Dinner. The project is divided into 3 sub-projects, `philo_one`, `philo_two`, `philo_three`, the 3 sub-projects answer the problem of the dinner, each with a different method.

**The common rules established were :**

- A number of philosophers sit at a round table and do one of three things: eat, think or sleep.
- When they eat, they don't think or sleep, when they sleep, they don't eat or think, and of course when they think, they don't eat or sleep.
- The philosophers are sitting at a circular table with a large bowl of spaghetti in the center.
- There are a few forks on the table.
- Since spaghetti is difficult to serve and eat with one fork, it is assumed that a philosopher must eat with two forks, one for each hand.
- Philosophers should never be hungry.
- Every philosopher needs to eat.
- Philosophers do not talk to each other.
- Philosophers do not know when another philosopher is about to die.
- Every time a philosopher is done eating, he drops his forks and goes to sleep.
- When a philosopher has finished sleeping, he starts to think.
- The simulation stops when a philosopher dies.
- Each program must have the same options: number_of_philosophers death_time eating_time sleeping_time [number_of_times_each_philosopher_must_eat].

### Main purpose :page_facing_up:
The project is based on learning several notions, **threads/processes** as well as **mutexes/semaphores**.

`Philo_one` represents the fact that each philosopher has a fork to his right and left via mutexes, while `philo_two` and `philo_three` represent forks arranged in the middle of the table, thanks to semaphores.

`Philo_one` and `philo_two` have philosophers that communicate with each other, represented by threads, while `philo_three` has one process for each philo, so memory is not shared.

### How to use :rocket:
Go to the folder, **philo_one**, **philo_two** or **philo_three**, then run `make`. Once compiled, you can run the program with those arguments:

``./philo_[number] [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] (Optional: [number_of_times_each_philosopher_must_eat])``

##### Examples

```
./philo_one 5 800 200 200
```
_no one should die_

```
./philo_two 5 800 200 200 7
```
_no one should die and the simulation should stop when all the philosopher has eaten 7 times_

```
./philo_three 4 410 200 200
```
_no one should die_

```
./philo_one 4 310 200 100
```
_a philosopher should die_
