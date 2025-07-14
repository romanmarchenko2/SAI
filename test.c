#include <stdio.h>
#include "sai.h"

const char* test_profile_get_value(_In_ sai_switch_profile_id_t profile_id, _In_ const char* variable)
{
    return 0;
}

int test_profile_get_next_value(_In_ sai_switch_profile_id_t profile_id, _Out_ const char** variable, _Out_ const char** value)
{
    return -1;
}

const service_method_table_t test_services = {
    test_profile_get_value,
    test_profile_get_next_value
};

int main()
{
    sai_status_t status;
    sai_lag_api_t *lag_api;
    sai_switch_api_t *switch_api;
    sai_object_id_t lag1_oid, lag2_oid;
    sai_object_id_t lag_member1_oid, lag_member2_oid, lag_member3_oid, lag_member4_oid;
    sai_object_id_t port_list[64];
    sai_attribute_t attrs[2];
    sai_switch_notification_t notifications;

    printf("Starting SAI LAG Test\n");

    status = sai_api_initialize(0, &test_services);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Failed to initialize SAI, status=%d\n", status);
        return 1;
    }

    status = sai_api_query(SAI_API_LAG, (void**)&lag_api);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Failed to query LAG API, status=%d\n", status);
        return 1;
    }
    printf("LAG API query successful!\n");

    status = sai_api_query(SAI_API_SWITCH, (void**)&switch_api);
    status = switch_api->initialize_switch(0, "HW_ID", 0, &notifications);
    
    attrs[0].id = SAI_SWITCH_ATTR_PORT_LIST;
    attrs[0].value.objlist.list = port_list;
    attrs[0].value.objlist.count = 64;
    status = switch_api->get_switch_attribute(1, attrs);

    printf("\n=== Creating LAGs ===\n");

    status = lag_api->create_lag(&lag1_oid, 0, NULL);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Failed to create LAG#1, status=%d\n", status);
        return 1;
    }

    status = lag_api->create_lag(&lag2_oid, 0, NULL);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Failed to create LAG#2, status=%d\n", status);
        return 1;
    }

    printf("\n=== Creating LAG Members ===\n");

    attrs[0].id = SAI_LAG_MEMBER_ATTR_LAG_ID;
    attrs[0].value.oid = lag1_oid;
    attrs[1].id = SAI_LAG_MEMBER_ATTR_PORT_ID;
    attrs[1].value.oid = port_list[0];
    status = lag_api->create_lag_member(&lag_member1_oid, 2, attrs);

    attrs[1].value.oid = port_list[1];
    status = lag_api->create_lag_member(&lag_member2_oid, 2, attrs);

    attrs[0].value.oid = lag2_oid;
    attrs[1].value.oid = port_list[2];
    status = lag_api->create_lag_member(&lag_member3_oid, 2, attrs);

    attrs[1].value.oid = port_list[3];
    status = lag_api->create_lag_member(&lag_member4_oid, 2, attrs);

    printf("\n=== Testing Get Attributes ===\n");
    printf("Get LAG#1 PORT_LIST:\n");
    lag_api->get_lag_attribute(lag1_oid, 0, NULL);
    
    printf("Get LAG#2 PORT_LIST:\n");
    lag_api->get_lag_attribute(lag2_oid, 0, NULL);
    
    printf("Get LAG_MEMBER#1 LAG_ID:\n");
    lag_api->get_lag_member_attribute(lag_member1_oid, 0, NULL);
    
    printf("Get LAG_MEMBER#3 PORT_ID:\n");
    lag_api->get_lag_member_attribute(lag_member3_oid, 0, NULL);

    printf("\n=== Removing LAG_MEMBER#2 ===\n");
    lag_api->remove_lag_member(lag_member2_oid);
    
    printf("Get LAG#1 PORT_LIST:\n");
    lag_api->get_lag_attribute(lag1_oid, 0, NULL);

    printf("\n=== Removing LAG_MEMBER#3 ===\n");
    lag_api->remove_lag_member(lag_member3_oid);
    
    printf("Get LAG#2 PORT_LIST:\n");
    lag_api->get_lag_attribute(lag2_oid, 0, NULL);

    printf("\n=== Final Cleanup ===\n");
    lag_api->remove_lag_member(lag_member1_oid);
    lag_api->remove_lag_member(lag_member4_oid);
    lag_api->remove_lag(lag2_oid);
    lag_api->remove_lag(lag1_oid);

    switch_api->shutdown_switch(0);
    sai_api_uninitialize();

    printf("\n=== Test Completed Successfully! ===\n");
    return 0;
}
