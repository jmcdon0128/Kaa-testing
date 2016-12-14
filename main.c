#include <stdio.h>
#include <stdlib.h>

#include <kaa.h>
#include <kaa_error.h>
#include <kaa_context.h>
#include <kaa_configuration_manager.h>
#include <platform/kaa_client.h>

static kaa_client_t *kaa_client = NULL;

kaa_error_t received_cb(void *context, const kaa_root_configuration_t *config)
{
    printf("Recieved config!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    kaa_client_stop(kaa_client);
    return KAA_ERR_NONE;
}

int main() 
{
    printf("\n****Running Test Application****\n\n\n");
    /* First We setup a new Kaa client */
    kaa_error_t error = kaa_client_create(&kaa_client, NULL);
    if (error)
    {
        printf("error!:%i\n", error);
        return EXIT_FAILURE;
    }
    
    // kaa_configuration_root_receiver_t receiver = 
    // {
    //     .context = NULL,
    //     .on_configuration_updated = &received_cb
    // };
    
    // error = kaa_configuration_manager_set_root_receiver
    // (
    //     kaa_client_get_context(kaa_client)->configuration_manager,
    //     &receiver
    // );
    // if (error)
    // {
    //     printf("Failed to add the config receiver");
    //     return EXIT_FAILURE;
    // }
    
    error = kaa_client_start(kaa_client, NULL, NULL, 0);
    if (error)
    {
        printf("cant start client!");
        return EXIT_FAILURE;
    }

    kaa_client_destroy(kaa_client);
        

    // /* Next we get the configuration settings from the server */
    // kaa_configuration_configuration_t *defualt_config = 
    //     kaa_configuration_manager_get_configuration();
    //     defualt_config.sample_period

    /* now we start the client loop */
    
    return 0;
    
}