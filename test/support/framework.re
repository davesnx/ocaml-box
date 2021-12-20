/** Initialize the test framework.

    Here we are specifying where snapshots should be stored as well as the root
    directory of the project for the formatting of terminal output. */;

include Rely.Make({
  let config =
    Rely.TestFrameworkConfig.initialize({
      snapshotDir: "test/_snapshots",
      projectDir: "",
    });
});

let equal = (s1, s2, expect) => {
  expect.string(String.trim(s1)).toEqual(String.trim(s2));
};
