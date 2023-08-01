-- This sample creates an incomming message

-- 123 = receiver
-- +393427330094 = sender
-- Hello world = body
-- otptest = destination ESME
-- c85d2a8e-96c0-494a-b94e-0f97f146d1ea = foreign message ID
-- do not touch the other params, they break stuff

INSERT INTO
  `smpp_store`
VALUES
  (
    NULL,
    '1233',
    '+393427330094',
    '',
    'Hello world',
    -1,
    'lp1',
    NULL,
    '14',
    'otptest',
    '',
    'c85d2a8e-96c0-494a-b94e-0f97f146d1ea',
    0,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    NULL,
    -1,
    -1,
    -1,
    '',
    NULL,
    '',
    -1,
    -1,
    -1,
    -1,
    ''
  );