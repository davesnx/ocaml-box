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
