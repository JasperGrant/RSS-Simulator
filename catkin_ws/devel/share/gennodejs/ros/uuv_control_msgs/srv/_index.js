
"use strict";

let ResetController = require('./ResetController.js')
let InitCircularTrajectory = require('./InitCircularTrajectory.js')
let AddWaypoint = require('./AddWaypoint.js')
let GetWaypoints = require('./GetWaypoints.js')
let SetSMControllerParams = require('./SetSMControllerParams.js')
let InitRectTrajectory = require('./InitRectTrajectory.js')
let IsRunningTrajectory = require('./IsRunningTrajectory.js')
let StartTrajectory = require('./StartTrajectory.js')
let GetSMControllerParams = require('./GetSMControllerParams.js')
let InitWaypointSet = require('./InitWaypointSet.js')
let GoToIncremental = require('./GoToIncremental.js')
let Hold = require('./Hold.js')
let SwitchToManual = require('./SwitchToManual.js')
let SwitchToAutomatic = require('./SwitchToAutomatic.js')
let InitWaypointsFromFile = require('./InitWaypointsFromFile.js')
let SetMBSMControllerParams = require('./SetMBSMControllerParams.js')
let InitHelicalTrajectory = require('./InitHelicalTrajectory.js')
let ClearWaypoints = require('./ClearWaypoints.js')
let GetPIDParams = require('./GetPIDParams.js')
let GoTo = require('./GoTo.js')
let SetPIDParams = require('./SetPIDParams.js')
let GetMBSMControllerParams = require('./GetMBSMControllerParams.js')

module.exports = {
  ResetController: ResetController,
  InitCircularTrajectory: InitCircularTrajectory,
  AddWaypoint: AddWaypoint,
  GetWaypoints: GetWaypoints,
  SetSMControllerParams: SetSMControllerParams,
  InitRectTrajectory: InitRectTrajectory,
  IsRunningTrajectory: IsRunningTrajectory,
  StartTrajectory: StartTrajectory,
  GetSMControllerParams: GetSMControllerParams,
  InitWaypointSet: InitWaypointSet,
  GoToIncremental: GoToIncremental,
  Hold: Hold,
  SwitchToManual: SwitchToManual,
  SwitchToAutomatic: SwitchToAutomatic,
  InitWaypointsFromFile: InitWaypointsFromFile,
  SetMBSMControllerParams: SetMBSMControllerParams,
  InitHelicalTrajectory: InitHelicalTrajectory,
  ClearWaypoints: ClearWaypoints,
  GetPIDParams: GetPIDParams,
  GoTo: GoTo,
  SetPIDParams: SetPIDParams,
  GetMBSMControllerParams: GetMBSMControllerParams,
};
