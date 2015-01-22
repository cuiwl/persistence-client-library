/******************************************************************************
 * Project         Persistency
 * (c) copyright   2015
 * Company         XS Embedded GmbH
 *****************************************************************************/
/******************************************************************************
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
******************************************************************************/
 /**
 * @file           persistence_client_library_tree_helper.c
 * @ingroup        Persistence client library
 * @author         Ingo Huerner
 * @brief          Implementation of persistence client library tree helper functions
 * @see
 */

#include "persistence_client_library_tree_helper.h"



jsw_rbtree_t *gKeyHandleTree = NULL;

jsw_rbtree_t *gFileHandleTree = NULL;

jsw_rbtree_t *gOssFileHandleTree = NULL;

/**
 * File handle helper functions
 */


// compare function for tree item
int fh_key_val_cmp(const void *p1, const void *p2)
{
   int rval = -1;

   FileHandleTreeItem_s* first;
   FileHandleTreeItem_s* second;

   first  = (FileHandleTreeItem_s*)p1;
   second = (FileHandleTreeItem_s*)p2;

   if(second->key == first->key)
   {
      rval = 0;
   }
   else if(second->key < first->key)
   {
      rval = -1;
   }
   else
   {
      rval = 1;
   }

   return rval;
 }



/// duplicate function for tree item
void* fh_key_val_dup(void *p)
{
   FileHandleTreeItem_s* dst = NULL;
   FileHandleTreeItem_s* src = (FileHandleTreeItem_s*)p;

   // allocate memory for node
   dst = malloc(sizeof(FileHandleTreeItem_s));

   if(dst != NULL)
   {
     dst->key = src->key;               // duplicate hash key

     memcpy(dst->value.payload , src->value.payload, sizeof(FileHandleData_u) ); // duplicate value
   }

   return dst;
}

/// release function for tree item
void  fh_key_val_rel(void *p)
{
   FileHandleTreeItem_s* rel = (FileHandleTreeItem_s*)p;

   if(rel != NULL)
      free(rel);
}




/**
 * Key handle helper functions
 */

/// compare function for tree item
int kh_key_val_cmp(const void *p1, const void *p2)
{
   int rval = -1;

   KeyHandleTreeItem_s* first;
   KeyHandleTreeItem_s* second;

   first  = (KeyHandleTreeItem_s*)p1;
   second = (KeyHandleTreeItem_s*)p2;

   if(second->key == first->key)
   {
      rval = 0;
   }
   else if(second->key < first->key)
   {
      rval = -1;
   }
   else
   {
      rval = 1;
   }
   return rval;
 }



/// duplicate function for tree item
void* kh_key_val_dup(void *p)
{
   KeyHandleTreeItem_s* dst = NULL;
   KeyHandleTreeItem_s* src = (KeyHandleTreeItem_s*)p;

   // allocate memory for node
   dst = malloc(sizeof(KeyHandleTreeItem_s));

   if(dst != NULL)
   {
     dst->key = src->key;               // duplicate hash key

     memcpy(dst->value.payload , src->value.payload, sizeof(KeyHandleData_u) ); // duplicate value
   }
   return dst;
}



/// release function for tree item
void  kh_key_val_rel(void *p)
{
   KeyHandleTreeItem_s* rel = (KeyHandleTreeItem_s*)p;

   if(rel != NULL)
      free(rel);
}
