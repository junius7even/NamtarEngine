set(prefix Include/ne)

set(core_headers
        ${prefix}/CoreComponents/Behaviour.h
        ${prefix}/CoreComponents/InputManager.h
        ${prefix}/CoreComponents/Physics/Collider2D.h
        ${prefix}/CoreComponents/Physics/Collision2DHandler.h
        ${prefix}/CoreComponents/SpriteRenderer.h
        ${prefix}/MonoInstance.h
        )

set(helper_headers
        ${prefix}/CoreComponents/Helper/json.hpp
        )

set(header_list
        ${core_headers}
        ${helper_headers}
        ${prefix}/Component.h
        ${prefix}/Engine.h
        ${prefix}/IDManager.h
        ${prefix}/GameObject.h
        ${prefix}/Logger.h
        )