/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#ifndef MODULES_PLANNING_SCENARIOS_SCENARIO_H_
#define MODULES_PLANNING_SCENARIOS_SCENARIO_H_

#include <string>

#include "modules/planning/proto/planning_config.pb.h"

#include "modules/common/status/status.h"
#include "modules/common/util/factory.h"

namespace apollo {
namespace planning {

class Scenario {
 public:
  Scenario() = default;

  explicit Scenario(const std::string& name) : name_(name) {}

  virtual ~Scenario() = default;

  virtual const std::string& Name() const;

  virtual bool Init();

  virtual common::Status Process() { return common::Status::OK(); }

 protected:
  bool is_init_ = false;
  const std::string name_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_SCENARIOS_SCENARIO_H_
