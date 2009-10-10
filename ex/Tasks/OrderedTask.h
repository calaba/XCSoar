/* Generated by Together */
#ifndef ORDEREDTASK_H
#define ORDEREDTASK_H

#include "Tasks/AbstractTask.h"
#include "BaseTask/OrderedTaskPoint.hpp"
#include "BaseTask/StartPoint.hpp"
#include "BaseTask/TaskLeg.h"
#include <vector>
#include "Util/Serialisable.hpp"
#include "GlideSolvers/MacCready.hpp"

class OrderedTask:
  public AbstractTask,
  public Serialisable
{
public:
  OrderedTask();
  ~OrderedTask();

  std::vector<OrderedTaskPoint*> tps;
  std::vector<TaskLeg*> legs;

  TaskPoint* getActiveTaskPoint();
  virtual void setActiveTaskPoint(unsigned);

  void insert(OrderedTaskPoint*, unsigned position);
  void remove(unsigned position);

  virtual bool update_sample(const AIRCRAFT_STATE &, const AIRCRAFT_STATE&);

  double get_distance_nominal() const {
    return distance_nominal;
  };
  double get_distance_min() const {
    return distance_min;
  };
  double get_distance_max() const {
    return distance_max;
  };
  double get_distance_remaining() const {
    return distance_remaining;
  };
  double get_distance_travelled() const {
    return distance_travelled;
  };
  double get_distance_scored() const {
    return distance_scored;
  };
  void report(const GEOPOINT &location);

private:
  double distance_nominal;
  double distance_min;
  double distance_max;
  double distance_remaining;
  double distance_travelled;
  double distance_scored;
  virtual void scan_distance(const GEOPOINT &location, bool full);
  void update_geometry();

  /**
   * @supplierCardinality 1 
   */
  StartPoint *ts;

  TaskProjection task_projection;

  GLIDE_RESULT glide_solution_remaining(const AIRCRAFT_STATE &, 
                                        const double mc);
  GLIDE_RESULT glide_solution_travelled(const AIRCRAFT_STATE &, 
                                        const double mc);
  double best_mc(const AIRCRAFT_STATE &, 
                 const double mc);
};

#endif //ORDEREDTASK_H
