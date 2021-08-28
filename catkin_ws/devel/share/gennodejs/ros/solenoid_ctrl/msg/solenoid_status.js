// Auto-generated. Do not edit!

// (in-package solenoid_ctrl.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class solenoid_status {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sol_ctrl = null;
      this.sol_bear = null;
      this.sol_thrust = null;
    }
    else {
      if (initObj.hasOwnProperty('sol_ctrl')) {
        this.sol_ctrl = initObj.sol_ctrl
      }
      else {
        this.sol_ctrl = false;
      }
      if (initObj.hasOwnProperty('sol_bear')) {
        this.sol_bear = initObj.sol_bear
      }
      else {
        this.sol_bear = false;
      }
      if (initObj.hasOwnProperty('sol_thrust')) {
        this.sol_thrust = initObj.sol_thrust
      }
      else {
        this.sol_thrust = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type solenoid_status
    // Serialize message field [sol_ctrl]
    bufferOffset = _serializer.bool(obj.sol_ctrl, buffer, bufferOffset);
    // Serialize message field [sol_bear]
    bufferOffset = _serializer.bool(obj.sol_bear, buffer, bufferOffset);
    // Serialize message field [sol_thrust]
    bufferOffset = _arraySerializer.int16(obj.sol_thrust, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type solenoid_status
    let len;
    let data = new solenoid_status(null);
    // Deserialize message field [sol_ctrl]
    data.sol_ctrl = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [sol_bear]
    data.sol_bear = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [sol_thrust]
    data.sol_thrust = _arrayDeserializer.int16(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.sol_thrust.length;
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'solenoid_ctrl/solenoid_status';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f071f78c9fde6c43f4fb013e9d377f82';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Reports the solenoid and control state of the solenoid_ctrl package
    bool sol_ctrl        # indicates whether key_sub is in control mode
    bool sol_bear        # indicates the status of the air bearing solenoid valve
    int16[] sol_thrust   # indicates the status of the thruster air bearings
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new solenoid_status(null);
    if (msg.sol_ctrl !== undefined) {
      resolved.sol_ctrl = msg.sol_ctrl;
    }
    else {
      resolved.sol_ctrl = false
    }

    if (msg.sol_bear !== undefined) {
      resolved.sol_bear = msg.sol_bear;
    }
    else {
      resolved.sol_bear = false
    }

    if (msg.sol_thrust !== undefined) {
      resolved.sol_thrust = msg.sol_thrust;
    }
    else {
      resolved.sol_thrust = []
    }

    return resolved;
    }
};

module.exports = solenoid_status;
