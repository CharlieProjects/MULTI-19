/* ==============================================================================
 * Script by: Juan Carlos Botero 
 * Date: 08/23/2020
 * Version: 1.0.0
 * ==============================================================================
 *                      Copyright (c) 2020 CHARLIE PROJECTS                      
 *                      github.com/CharlieProjects/MULTI-19                      
 * ==============================================================================
 * =======================  GOLDEN MOTOR FOC CONTROLLER  ========================
 * ==============================================================================
 * MIT license. See LICENSE file in the project root for full license information
 */

#include <GoldenMotor.h>

GoldenMotor::GoldenMotor(byte S1, byte S2, byte S3)
{
    _S1 = S1, _S2 = S2, _S3 = S3;
}

GoldenMotor::begin()
{
}

GoldenMotor::test()
{
}