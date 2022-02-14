/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2020      Google, LLC. All rights reserved.
 * Copyright (c) 2021-2022 Nanook Consulting.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef PRTE_MCA_BASE_ALIAS_H
#define PRTE_MCA_BASE_ALIAS_H

#include "prte_config.h"
#include "src/class/pmix_list.h"

BEGIN_C_DECLS

enum prte_mca_base_alias_flags_t {
    PRTE_MCA_BASE_ALIAS_FLAG_NONE = 0,
    /** The aliased name has been deprecated. */
    PRTE_MCA_BASE_ALIAS_FLAG_DEPRECATED = 1,
};

typedef enum prte_mca_base_alias_flags_t prte_mca_base_alias_flags_t;

struct prte_mca_base_alias_item_t {
    pmix_list_item_t super;
    /** Name aias. */
    char *component_alias;
    /** Alias flags. */
    uint32_t alias_flags;
};

typedef struct prte_mca_base_alias_item_t prte_mca_base_alias_item_t;

PMIX_CLASS_DECLARATION(prte_mca_base_alias_item_t);

struct prte_mca_base_alias_t {
    pmix_object_t super;
    /** List of name aliases. */
    pmix_list_t component_aliases;
};

typedef struct prte_mca_base_alias_t prte_mca_base_alias_t;

PMIX_CLASS_DECLARATION(prte_mca_base_alias_t);

/**
 * @brief Create a alias for a component name.
 *
 * @param[in] project         Project name (may be NULL)
 * @param[in] framework       Framework name (may be NULL)
 * @param[in] component_name  Name of component to alias (may not be NULL)
 * @param[in] component_alias Aliased name (may not be NULL)
 * @param[in] alias_flags     Flags (see mca_base_alias_flags_t)
 *
 * This function aliases one component name to another. When aliased
 * any variable registered with this project, framework, and
 * component_name will have synonyms created. For example, if
 * prte_btl_vader is aliased to sm then registers a variable
 * named btl_vader_flags then a synonym will be created with the
 * name btl_sm_flags. If an alias is registered early enough
 * (during framework registration for example) then the alias can
 * also be used for component selection. In the previous example
 * --mca btl vader and --mca btl sm would select the same
 * component if the synonym is registered in the btl framework
 * registration function.
 */
PRTE_EXPORT int prte_mca_base_alias_register(const char *project, const char *framework,
                                             const char *component_name,
                                             const char *component_alias, uint32_t alias_flags);

/**
 * @brief Check for aliases for a component.
 *
 * @param[in] project        Project name (may be NULL)
 * @param[in] frameworek     Framework name (may be NULL)
 * @param[in] component_name Component name (may not be NULL)
 */
PRTE_EXPORT const prte_mca_base_alias_t *
prte_mca_base_alias_lookup(const char *project, const char *framework, const char *component_name);

PRTE_EXPORT void prte_mca_base_alias_cleanup(void);

#endif /* PRTE_MCA_BASE_ALIAS_H */
