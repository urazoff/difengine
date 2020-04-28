Getting Started
===============================

**Quick start:**

Let's get sources and tools first:
*   Install meson build system
*   Clone repo

Once we've got source code and required tools, we are to proceed:

.. code-block:: console

        cd difengine
        chmod a+x scripts/test_build_run.sh
        scripts/test_build_run.sh -v

Use ```-v``` option in the latter script to get verbose output.

The following will happen:

*   Difengine libs build,

*   Difengine tests build,

*   Difengine test suites run.

And you will see something like following:

.. code-block:: console

        Run Stack frame object test...
        DISASSEMBLE test_frame->code
        0000    1 RETURN_VALUE
        0001    2 LOAD_CONST    0 17
        PASS
        Success
