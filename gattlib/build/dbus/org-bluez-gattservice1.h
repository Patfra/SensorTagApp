/*
 * Generated by gdbus-codegen 2.50.3. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef ___HOME_PATRYK_DOKUMENTY_SENSORTAGAPP_GATTLIB_BUILD_DBUS_ORG_BLUEZ_GATTSERVICE1_H__
#define ___HOME_PATRYK_DOKUMENTY_SENSORTAGAPP_GATTLIB_BUILD_DBUS_ORG_BLUEZ_GATTSERVICE1_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.bluez.GattService1 */

#define TYPE_ORG_BLUEZ_GATT_SERVICE1 (org_bluez_gatt_service1_get_type ())
#define ORG_BLUEZ_GATT_SERVICE1(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1, OrgBluezGattService1))
#define IS_ORG_BLUEZ_GATT_SERVICE1(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1))
#define ORG_BLUEZ_GATT_SERVICE1_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1, OrgBluezGattService1Iface))

struct _OrgBluezGattService1;
typedef struct _OrgBluezGattService1 OrgBluezGattService1;
typedef struct _OrgBluezGattService1Iface OrgBluezGattService1Iface;

struct _OrgBluezGattService1Iface
{
  GTypeInterface parent_iface;


  const gchar *const * (*get_characteristics) (OrgBluezGattService1 *object);

  const gchar * (*get_device) (OrgBluezGattService1 *object);

  gboolean  (*get_primary) (OrgBluezGattService1 *object);

  const gchar * (*get_uuid) (OrgBluezGattService1 *object);

  void (*properties_changed) (
    OrgBluezGattService1 *object,
    const gchar *arg_interface,
    GVariant *arg_changed_properties,
    const gchar *const *arg_invalidated_properties);

};

GType org_bluez_gatt_service1_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *org_bluez_gatt_service1_interface_info (void);
guint org_bluez_gatt_service1_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus signal emissions functions: */
void org_bluez_gatt_service1_emit_properties_changed (
    OrgBluezGattService1 *object,
    const gchar *arg_interface,
    GVariant *arg_changed_properties,
    const gchar *const *arg_invalidated_properties);



/* D-Bus property accessors: */
const gchar *org_bluez_gatt_service1_get_uuid (OrgBluezGattService1 *object);
gchar *org_bluez_gatt_service1_dup_uuid (OrgBluezGattService1 *object);
void org_bluez_gatt_service1_set_uuid (OrgBluezGattService1 *object, const gchar *value);

const gchar *org_bluez_gatt_service1_get_device (OrgBluezGattService1 *object);
gchar *org_bluez_gatt_service1_dup_device (OrgBluezGattService1 *object);
void org_bluez_gatt_service1_set_device (OrgBluezGattService1 *object, const gchar *value);

gboolean org_bluez_gatt_service1_get_primary (OrgBluezGattService1 *object);
void org_bluez_gatt_service1_set_primary (OrgBluezGattService1 *object, gboolean value);

const gchar *const *org_bluez_gatt_service1_get_characteristics (OrgBluezGattService1 *object);
gchar **org_bluez_gatt_service1_dup_characteristics (OrgBluezGattService1 *object);
void org_bluez_gatt_service1_set_characteristics (OrgBluezGattService1 *object, const gchar *const *value);


/* ---- */

#define TYPE_ORG_BLUEZ_GATT_SERVICE1_PROXY (org_bluez_gatt_service1_proxy_get_type ())
#define ORG_BLUEZ_GATT_SERVICE1_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1_PROXY, OrgBluezGattService1Proxy))
#define ORG_BLUEZ_GATT_SERVICE1_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ORG_BLUEZ_GATT_SERVICE1_PROXY, OrgBluezGattService1ProxyClass))
#define ORG_BLUEZ_GATT_SERVICE1_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1_PROXY, OrgBluezGattService1ProxyClass))
#define IS_ORG_BLUEZ_GATT_SERVICE1_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1_PROXY))
#define IS_ORG_BLUEZ_GATT_SERVICE1_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ORG_BLUEZ_GATT_SERVICE1_PROXY))

typedef struct _OrgBluezGattService1Proxy OrgBluezGattService1Proxy;
typedef struct _OrgBluezGattService1ProxyClass OrgBluezGattService1ProxyClass;
typedef struct _OrgBluezGattService1ProxyPrivate OrgBluezGattService1ProxyPrivate;

struct _OrgBluezGattService1Proxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  OrgBluezGattService1ProxyPrivate *priv;
};

struct _OrgBluezGattService1ProxyClass
{
  GDBusProxyClass parent_class;
};

GType org_bluez_gatt_service1_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (OrgBluezGattService1Proxy, g_object_unref)
#endif

void org_bluez_gatt_service1_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
OrgBluezGattService1 *org_bluez_gatt_service1_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
OrgBluezGattService1 *org_bluez_gatt_service1_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void org_bluez_gatt_service1_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
OrgBluezGattService1 *org_bluez_gatt_service1_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
OrgBluezGattService1 *org_bluez_gatt_service1_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_ORG_BLUEZ_GATT_SERVICE1_SKELETON (org_bluez_gatt_service1_skeleton_get_type ())
#define ORG_BLUEZ_GATT_SERVICE1_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1_SKELETON, OrgBluezGattService1Skeleton))
#define ORG_BLUEZ_GATT_SERVICE1_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ORG_BLUEZ_GATT_SERVICE1_SKELETON, OrgBluezGattService1SkeletonClass))
#define ORG_BLUEZ_GATT_SERVICE1_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1_SKELETON, OrgBluezGattService1SkeletonClass))
#define IS_ORG_BLUEZ_GATT_SERVICE1_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ORG_BLUEZ_GATT_SERVICE1_SKELETON))
#define IS_ORG_BLUEZ_GATT_SERVICE1_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ORG_BLUEZ_GATT_SERVICE1_SKELETON))

typedef struct _OrgBluezGattService1Skeleton OrgBluezGattService1Skeleton;
typedef struct _OrgBluezGattService1SkeletonClass OrgBluezGattService1SkeletonClass;
typedef struct _OrgBluezGattService1SkeletonPrivate OrgBluezGattService1SkeletonPrivate;

struct _OrgBluezGattService1Skeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  OrgBluezGattService1SkeletonPrivate *priv;
};

struct _OrgBluezGattService1SkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType org_bluez_gatt_service1_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (OrgBluezGattService1Skeleton, g_object_unref)
#endif

OrgBluezGattService1 *org_bluez_gatt_service1_skeleton_new (void);


G_END_DECLS

#endif /* ___HOME_PATRYK_DOKUMENTY_SENSORTAGAPP_GATTLIB_BUILD_DBUS_ORG_BLUEZ_GATTSERVICE1_H__ */
