//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: time_to_collision.cpp
//
// Code generated for Simulink model 'time_to_collision'.
//
// Model version                  : 3.91
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Mar 17 14:37:21 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "time_to_collision.h"
#include "time_to_collision_private.h"

// Block signals (default storage)
B_time_to_collision_T time_to_collision_B;

// Block states (default storage)
DW_time_to_collision_T time_to_collision_DW;

// Real-time model
RT_MODEL_time_to_collision_T time_to_collision_M_ = RT_MODEL_time_to_collision_T
  ();
RT_MODEL_time_to_collision_T *const time_to_collision_M = &time_to_collision_M_;

// Model step function
void time_to_collision_step(void)
{
  SL_Bus_time_to_collision_std_msgs_Bool b_varargout_2_0;
  SL_Bus_time_to_collision_std_msgs_Float64 b_varargout_2;
  SL_Bus_time_to_collision_std_msgs_Float64 rtb_BusAssignment1;
  real_T rtb_minmax3015;
  real_T rtb_safe_accel;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
  // MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Inport: '<S15>/In1'

  b_varargout_1 = Sub_time_to_collision_476.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (b_varargout_1) {
    time_to_collision_B.In1_o = b_varargout_2;
  }

  // End of MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe6'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S12>/In1'

  b_varargout_1 = Sub_time_to_collision_429.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (b_varargout_1) {
    time_to_collision_B.In1_m = b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S13>/In1'

  b_varargout_1 = Sub_time_to_collision_430.getLatestMessage
    (&time_to_collision_B.BusAssignment2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1) {
    time_to_collision_B.In1 = time_to_collision_B.BusAssignment2;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   SignalConversion generated from: '<Root>/Bus Selector7'

  rtb_safe_accel = time_to_collision_B.In1.Linear.Z *
    time_to_collision_B.In1.Linear.Z;
  rtb_minmax3015 = -rtb_safe_accel / (2.0 * time_to_collision_B.In1_m.Data);
  if (!(rtb_minmax3015 > -3.0)) {
    rtb_minmax3015 = -3.0;
  }

  rtb_safe_accel = static_cast<real_T>(rtb_safe_accel / 2.0 <
    time_to_collision_B.In1_m.Data) * 3.0 + rtb_minmax3015;
  if ((time_to_collision_B.In1_o.Data < rtb_safe_accel) || rtIsNaN
      (rtb_safe_accel)) {
    rtb_safe_accel = time_to_collision_B.In1_o.Data;
  }

  // End of MATLAB Function: '<S11>/MATLAB Function1'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant2'
  //   SignalConversion generated from: '<Root>/Bus Selector7'

  if (time_to_collision_P.Constant2_Value > time_to_collision_P.Switch_Threshold)
  {
    // MinMax: '<Root>/MinMax' incorporates:
    //   SignalConversion generated from: '<Root>/Bus Selector7'

    if ((rtb_safe_accel < time_to_collision_B.In1_o.Data) || rtIsNaN
        (time_to_collision_B.In1_o.Data)) {
      rtb_minmax3015 = rtb_safe_accel;
    } else {
      rtb_minmax3015 = time_to_collision_B.In1_o.Data;
    }

    // End of MinMax: '<Root>/MinMax'
  } else {
    rtb_minmax3015 = time_to_collision_B.In1_o.Data;
  }

  // End of Switch: '<Root>/Switch'

  // Saturate: '<Root>/min//max -3.0//1.5'
  if (rtb_minmax3015 > time_to_collision_P.minmax3015_UpperSat) {
    rtb_minmax3015 = time_to_collision_P.minmax3015_UpperSat;
  } else if (rtb_minmax3015 < time_to_collision_P.minmax3015_LowerSat) {
    rtb_minmax3015 = time_to_collision_P.minmax3015_LowerSat;
  }

  // End of Saturate: '<Root>/min//max -3.0//1.5'

  // BusAssignment: '<Root>/Bus Assignment1'
  rtb_BusAssignment1.Data = rtb_minmax3015;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_time_to_collision_401.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<S2>/Constant'
  //   SignalConversion generated from: '<Root>/Bus Selector7'

  time_to_collision_B.BusAssignment2 = time_to_collision_P.Constant_Value;
  time_to_collision_B.BusAssignment2.Linear.X = time_to_collision_B.In1_o.Data;
  time_to_collision_B.BusAssignment2.Linear.Y = rtb_safe_accel;
  time_to_collision_B.BusAssignment2.Linear.Z = rtb_minmax3015;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_time_to_collision_520.publish(&time_to_collision_B.BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // MATLAB Function: '<Root>/MATLAB Function1'
  time_to_collision_DW.relative_distance_prev_not_empt = true;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe5'
  // MATLABSystem: '<S8>/SourceBlock'
  Sub_time_to_collision_431.getLatestMessage(&time_to_collision_B.BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Subscribe5'

  // MATLABSystem: '<S11>/Get Parameter6'
  ParamGet_time_to_collision_465.get_parameter(&rtb_safe_accel);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe7'
  // MATLABSystem: '<S10>/SourceBlock'
  Sub_time_to_collision_481.getLatestMessage(&b_varargout_2_0);

  // End of Outputs for SubSystem: '<Root>/Subscribe7'
}

// Model initialize function
void time_to_collision_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic[14];
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic_1[8];
    char_T b_zeroDelimTopic_2[4];
    char_T b_zeroDelimName[3];
    static const char_T tmp[13] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l',
      '_', 'p', 'r', 'e' };

    static const char_T tmp_0[9] = { 'l', 'e', 'a', 'd', '_', 'd', 'i', 's', 't'
    };

    static const char_T tmp_1[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    static const char_T tmp_3[41] = { 't', 'i', 'm', 'e', '_', 't', 'o', '_',
      'c', 'o', 'l', 'l', 'i', 's', 'i', 'o', 'n', '/', 't', 'i', 'm', 'e', '_',
      't', 'o', '_', 'c', 'o', 'l', 'l', 'i', 's', 'i', 'o', 'n', '_', 'd', 'e',
      'b', 'u', 'g' };

    static const char_T tmp_4[24] = { '/', 'c', 'a', 'r', '/', 'h', 'u', 'd',
      '/', 'm', 'i', 'n', 'i', '_', 'c', 'a', 'r', '_', 'e', 'n', 'a', 'b', 'l',
      'e' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S15>/Out1' incorporates:
    //   Inport: '<S15>/In1'

    time_to_collision_B.In1_o = time_to_collision_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    time_to_collision_DW.obj_n.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[13] = '\x00';
    Sub_time_to_collision_476.createSubscriber(&b_zeroDelimTopic[0], 1);
    time_to_collision_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S12>/Out1' incorporates:
    //   Inport: '<S12>/In1'

    time_to_collision_B.In1_m = time_to_collision_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    time_to_collision_DW.obj_f.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Sub_time_to_collision_429.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    time_to_collision_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S13>/Out1' incorporates:
    //   Inport: '<S13>/In1'

    time_to_collision_B.In1 = time_to_collision_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    time_to_collision_DW.obj_o.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    Sub_time_to_collision_430.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    time_to_collision_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    time_to_collision_DW.obj_c.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_2[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Pub_time_to_collision_401.createPublisher(&b_zeroDelimTopic_0[0], 1);
    time_to_collision_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    time_to_collision_DW.obj_j.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 41; i++) {
      time_to_collision_B.b_zeroDelimTopic[i] = tmp_3[i];
    }

    time_to_collision_B.b_zeroDelimTopic[41] = '\x00';
    Pub_time_to_collision_520.createPublisher
      (&time_to_collision_B.b_zeroDelimTopic[0], 1);
    time_to_collision_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe5'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    time_to_collision_DW.obj_i.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_i.isInitialized = 1;
    b_zeroDelimTopic_2[0] = 'v';
    b_zeroDelimTopic_2[1] = 'e';
    b_zeroDelimTopic_2[2] = 'l';
    b_zeroDelimTopic_2[3] = '\x00';
    Sub_time_to_collision_431.createSubscriber(&b_zeroDelimTopic_2[0], 1);
    time_to_collision_DW.obj_i.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe5'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe7'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    time_to_collision_DW.obj_d.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      time_to_collision_B.b_zeroDelimTopic_m[i] = tmp_4[i];
    }

    time_to_collision_B.b_zeroDelimTopic_m[24] = '\x00';
    Sub_time_to_collision_481.createSubscriber
      (&time_to_collision_B.b_zeroDelimTopic_m[0], 1);
    time_to_collision_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe7'

    // Start for MATLABSystem: '<S11>/Get Parameter6'
    time_to_collision_DW.obj.matlabCodegenIsDeleted = false;
    time_to_collision_DW.obj.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '3';
    b_zeroDelimName[2] = '\x00';
    ParamGet_time_to_collision_465.initialize(&b_zeroDelimName[0]);
    ParamGet_time_to_collision_465.initialize_error_codes(0, 1, 2, 3);
    ParamGet_time_to_collision_465.set_initial_value(6.0);
    time_to_collision_DW.obj.isSetupComplete = true;
  }
}

// Model terminate function
void time_to_collision_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!time_to_collision_DW.obj_n.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!time_to_collision_DW.obj_f.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!time_to_collision_DW.obj_o.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!time_to_collision_DW.obj_c.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!time_to_collision_DW.obj_j.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe5'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!time_to_collision_DW.obj_i.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe5'

  // Terminate for MATLABSystem: '<S11>/Get Parameter6'
  if (!time_to_collision_DW.obj.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe7'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!time_to_collision_DW.obj_d.matlabCodegenIsDeleted) {
    time_to_collision_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe7'
}

//
// File trailer for generated code.
//
// [EOF]
//
