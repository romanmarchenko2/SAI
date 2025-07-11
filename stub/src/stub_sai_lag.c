/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    stub_sai_lag.c
 *
 * @brief   This module defines SAI LAG interface stubs
 */

#include "sai_stub.h"

/**
 * @brief Create LAG
 */
static sai_status_t stub_create_lag(
    _Out_ sai_object_id_t *lag_id,
    _In_ sai_object_id_t switch_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG creation logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Remove LAG
 */
static sai_status_t stub_remove_lag(
    _In_ sai_object_id_t lag_id)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG removal logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Set LAG attribute
 */
static sai_status_t stub_set_lag_attribute(
    _In_ sai_object_id_t lag_id,
    _In_ const sai_attribute_t *attr)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG attribute setting logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Get LAG attribute
 */
static sai_status_t stub_get_lag_attribute(
    _In_ sai_object_id_t lag_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG attribute getting logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Create LAG member
 */
static sai_status_t stub_create_lag_member(
    _Out_ sai_object_id_t *lag_member_id,
    _In_ sai_object_id_t switch_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG member creation logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Remove LAG member
 */
static sai_status_t stub_remove_lag_member(
    _In_ sai_object_id_t lag_member_id)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG member removal logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Set LAG member attribute
 */
static sai_status_t stub_set_lag_member_attribute(
    _In_ sai_object_id_t lag_member_id,
    _In_ const sai_attribute_t *attr)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG member attribute setting logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief Get LAG member attribute
 */
static sai_status_t stub_get_lag_member_attribute(
    _In_ sai_object_id_t lag_member_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list)
{
    STUB_LOG_ENTER();

    // TODO: Implement LAG member attribute getting logic

    STUB_LOG_EXIT();
    return SAI_STATUS_NOT_IMPLEMENTED;
}

/**
 * @brief LAG methods table retrieved with sai_api_query()
 */
const sai_lag_api_t lag_api = {
    stub_create_lag,
    stub_remove_lag,
    stub_set_lag_attribute,
    stub_get_lag_attribute,
    stub_create_lag_member,
    stub_remove_lag_member,
    stub_set_lag_member_attribute,
    stub_get_lag_member_attribute
};
