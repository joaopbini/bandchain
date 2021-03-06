[@react.component]
let make = (~value, ~size, ~weight, ~spacing) => {
  let countup =
    Countup.context(
      Countup.props(
        ~start=value,
        ~end_=value,
        ~delay=0,
        ~decimals=6,
        ~duration=4,
        ~useEasing=false,
        ~separator=",",
      ),
    );

  React.useEffect1(
    _ => {
      Countup.updateGet(countup, value);
      None;
    },
    [|value|],
  );

  let newVal = Countup.countUpGet(countup);
  <Text value={newVal} size weight spacing code=true nowrap=true />;
};
