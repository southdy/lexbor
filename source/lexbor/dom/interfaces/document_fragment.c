/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

#include "lexbor/dom/interfaces/document_fragment.h"
#include "lexbor/dom/interfaces/document.h"


lxb_dom_document_fragment_t *
lxb_dom_document_fragment_interface_create(lxb_dom_document_t *document)
{
    lxb_dom_document_fragment_t *element;

    element = lexbor_mraw_calloc(document->mraw,
                                 sizeof(lxb_dom_document_fragment_t));
    if (element == NULL) {
        return NULL;
    }

    lxb_dom_node_t *node = lxb_dom_interface_node(element);

    node->owner_document = document;
    node->type = LXB_DOM_NODE_TYPE_DOCUMENT_FRAGMENT;

    return element;
}

lxb_dom_document_fragment_t *
lxb_dom_document_fragment_interface_destroy(lxb_dom_document_fragment_t *document_fragment)
{
    return lexbor_mraw_free(
        lxb_dom_interface_node(document_fragment)->owner_document->mraw,
        document_fragment);
}
