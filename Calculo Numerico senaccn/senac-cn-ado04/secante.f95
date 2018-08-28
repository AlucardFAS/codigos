PROGRAM secante
    IMPLICIT NONE

    INTEGER :: max = 1000, i
    DOUBLE PRECISION :: in, p0, p, p1, erro = 1E-6
    CHARACTER(len = 32) :: arg
    CALL get_command_argument(1, arg)
    READ (arg, *) in

    p0 = in
    p = in - 1.0
    DO i = 1, max
        p1 = (p0 * p + in) / (p0 + p)
        IF (abs(p1 - p) < erro .OR. p1 ** 2 == in) THEN
            PRINT *, REAL(p1)
            EXIT
        END IF
        p0 = p
        p = p1   
    END DO

END PROGRAM